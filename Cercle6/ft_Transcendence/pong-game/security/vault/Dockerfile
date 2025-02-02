# Debian image
FROM debian:latest

# Set env vars
ENV VAULT_VERSION=1.18.1
ENV VAULT_SHA256SUM=d6486e4644cbeefa841ff6a41e39b68a5129c329bd2e271b29368948ff9ddfc4

# Install dependencies
RUN apt-get update && apt-get install -y \
    wget \
	curl \
    unzip \
    vim \
    ca-certificates \
	openssl \
    jq \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Download and setup vault
RUN wget https://releases.hashicorp.com/vault/${VAULT_VERSION}/vault_${VAULT_VERSION}_linux_amd64.zip \
    && echo "${VAULT_SHA256SUM} vault_${VAULT_VERSION}_linux_amd64.zip" | sha256sum -c - \
    && unzip vault_${VAULT_VERSION}_linux_amd64.zip \
    && mv vault /usr/local/bin/ \
    && chmod +x /usr/local/bin/vault \
    && rm vault_${VAULT_VERSION}_linux_amd64.zip

# Create non root user
# RUN useradd --no-create-home --shell /bin/false vault
RUN useradd -r -m -d /home/vault -s /bin/bash vault && \
    touch /home/vault/.vault-token && \
    chown -R vault:vault /home/vault/.vault-token && \
    chmod 600 /home/vault/.vault-token

ENV VAULT_ADDR="https://127.0.0.1:8200" \
    VAULT_CACERT="/vault/certs/selfsigned.crt" \
    HOME="/home/vault"

# Add vault config dir
RUN mkdir -p /etc/vault.d /var/lib/vault \
    && chown -R vault:vault /etc/vault.d /var/lib/vault

# Add vault config file
COPY vault.hcl /etc/vault.d/vault.hcl
RUN chown vault:vault /etc/vault.d/vault.hcl

# Generate ssl certificates
RUN mkdir -p /vault/certs && \
    # Create a config file for the certificate
    echo "[req]" > /vault/certs/openssl.conf && \
    echo "distinguished_name = req_distinguished_name" >> /vault/certs/openssl.conf && \
    echo "x509_extensions = v3_req" >> /vault/certs/openssl.conf && \
    echo "prompt = no" >> /vault/certs/openssl.conf && \
    echo "[req_distinguished_name]" >> /vault/certs/openssl.conf && \
    echo "CN = vault" >> /vault/certs/openssl.conf && \
    echo "[v3_req]" >> /vault/certs/openssl.conf && \
    echo "subjectAltName = @alt_names" >> /vault/certs/openssl.conf && \
    echo "[alt_names]" >> /vault/certs/openssl.conf && \
    echo "DNS.1 = vault" >> /vault/certs/openssl.conf && \
    echo "DNS.2 = localhost" >> /vault/certs/openssl.conf && \
    echo "IP.1 = 127.0.0.1" >> /vault/certs/openssl.conf && \
    # Generate the certificate using the above config
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /vault/certs/selfsigned.key \
    -out /vault/certs/selfsigned.crt \
    -config /vault/certs/openssl.conf && \
    # -subj "/C=US/ST=State/L=City/O=Organization/OU=Unit/CN=vault" && \
    chown -R vault:vault /vault/certs
    # chown -R vault:vault /vault/certs/selfsigned.crt /vault/certs/selfsigned.key

# Copy init script
COPY init.sh /init.sh
RUN chown -R vault:vault /init.sh

# Add volume dirs
RUN mkdir -p /vault/file && \
    chown -R vault:vault /vault/file
RUN mkdir -p /vault/shared_data && \
    chown -R vault:vault /vault/shared_data
RUN chown -R vault:vault /vault/

EXPOSE 8200

USER vault

STOPSIGNAL SIGINT

ENTRYPOINT ["sh", "./init.sh"]