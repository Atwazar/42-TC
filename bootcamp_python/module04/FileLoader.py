# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    FileLoader.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 09:22:43 by thelaine          #+#    #+#              #
#    Updated: 2024/06/14 16:51:16 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

class FileLoader:
    def load(self, path):
        df = pd.read_csv(path)
        print(f"Loading dataset of dimensions {len(df)}x{len(df.axes[1])}")
        return df 
    def display(self, df, n):
        if n > 0:
            df1 = df.iloc[:, 0:n]
        if n < 0:
            df1 = df.iloc[:,n:len(df)]
        print(df1.to_string())

class YoungestFellah:
    def youngest_fellah(self, df, year):
        young_man = df.loc[df["Year"] == year].loc[df["Sex"] == "M"].nsmallest(1, 'Age')
        young_woman = df.loc[df["Year"] == year].loc[df["Sex"] == "F"].nsmallest(1, 'Age')
        return dict({'young_man': young_man['Age'].to_list()[0], 'young_woman': young_woman['Age'].to_list()[0]})

class ProportionBySport:
    def proportion_by_sport(self, df, year, sport, gender):
        list_by_sport = df.loc[df["Year"] == year].loc[df["Sex"] == gender].loc[df["Sport"] == sport]
        list_by_year = df.loc[df["Year"] == year].loc[df["Sex"] == gender]
        list_by_sport.drop_duplicates(subset=['Name'], inplace = True)
        list_by_year.drop_duplicates(subset=['Name'], inplace = True)
        return len(list_by_sport) / len(list_by_year) * 100

class HowManyMedals:
    def how_many_medals(self, df, name):
        list_by_name = df.loc[df['Name'] == name]
        #print(list_by_name.to_string())
        list_year = list_by_name.drop_duplicates(subset=['Year'], inplace = False)['Year'].to_list()
        #print(list_year)
        big_dic = {}
        for year in list_year:
            G = len(list_by_name.loc[df["Year"] == year].loc[df["Medal"] == 'Gold'])
            S = len(list_by_name.loc[df["Year"] == year].loc[df["Medal"] == 'Silver'])
            B = len(list_by_name.loc[df["Year"] == year].loc[df["Medal"] == 'Bronze'])
            big_dic[year] = {'Gold': G, 'Silver': S, 'Bronze': B}
        return big_dic

class SpatioTemporalData:
    def when(self, location):
        return df.loc[df['City'] == location].drop_duplicates(subset=["Year"], inplace = False)["Year"].to_list() 
    
    def where(self, year):
        return df.loc[df['Year'] == year].drop_duplicates(subset=["City"], inplace = False)["City"].to_list() 

class HowManyMedalsByCountry:
    def how_many_medals_by_country(self, df, country):
        list_by_country = df.loc[df['Team'] == country]
        list_year = list_by_country.drop_duplicates(subset=['Year'], inplace = False)['Year'].to_list()
        list_sport = list_by_country.drop_duplicates(subset=['Sport'], inplace = False)['Sport'].to_list()
        list_team_sports = ['Basketball', 'Football', 'Tug-Of-War', 'Badminton', 'Handball', 'Water Polo', 'Hockey', 'Rowing', 'B', 
        'Volleyball', 'Synchronized Swimming', 'Baseball', 'Rugby', 'Lacrosse', 'Polo']
        big_dic = {}
        for year in list_year:
            G = 0
            S = 0
            B = 0
            for sport in list_sport:
                if sport not in list_team_sports:
                    G += len(list_by_country.loc[df["Sport"] == sport].loc[df["Year"] == year].loc[df["Medal"] == 'Gold'])
                    S += len(list_by_country.loc[df["Sport"] == sport].loc[df["Year"] == year].loc[df["Medal"] == 'Silver'])
                    B += len(list_by_country.loc[df["Sport"] == sport].loc[df["Year"] == year].loc[df["Medal"] == 'Bronze'])
                else:
                    G += len(list_by_country.loc[df["Sport"] == sport].loc[df["Year"] == year].loc[df["Medal"] == 'Gold'].drop_duplicates(subset=['Year'], inplace = False))
                    S += len(list_by_country.loc[df["Sport"] == sport].loc[df["Year"] == year].loc[df["Medal"] == 'Silver'].drop_duplicates(subset=['Year'], inplace = False))
                    B += len(list_by_country.loc[df["Sport"] == sport].loc[df["Year"] == year].loc[df["Medal"] == 'Bronze'].drop_duplicates(subset=['Year'], inplace = False))
            big_dic[year] = {'Gold': G, 'Silver': S, 'Bronze': B}
        return big_dic

class MyPlotLib:
    def histogram(self, df, features):
        figure, axis = plt.subplots(1, len(features), sharey = True)
        for i in range(len(features)):
            list_feat = df[features[i]]
            axis[i].hist(list_feat, color='skyblue', edgecolor='black')
            axis[i].set_title(f'Histogram for {features[i]}')
        plt.show()
    
    def density(self, df, features):
        for feat in features:
            list_feat = df[feat]
            sns.kdeplot(list_feat, fill = True, label = feat)
            plt.legend()
        plt.show()
    def pair_plot(self, df, features):
        figure, axis = plt.subplots(len(features), len(features))
        for i in range(len(features)):
            for j in range(len(features)):
                if i == j:
                    axis[i][j].hist(df[features[i]], color='skyblue', edgecolor='black')
                    axis[i][j].set_title(features[i])
                else:
                    axis[i][j].scatter(df[features[i]], df[features[j]])
                    axis[i][j].set_title(f"{features[i]}/{features[j]}")
        plt.show()
    def box_plot(self, df, features):
        for feat in features:
            sns.boxplot(df[feat])
        plt.show()

class Komparator:
    def __init__(self, df):
        self.data =  df
    def compare_box_plots(self, categorical_var, numerical_var):
        categorical_list = self.data.drop_duplicates(subset=[categorical_var], inplace = False)[categorical_var].to_list()
        for category in categorical_list:
            sns.boxplot(df[numerical_var].loc[df[categorical_var] == category], label = category)
            plt.legend()
        plt.show()
    def density(self, categorical_var, numerical_var):
        categorical_list = self.data.drop_duplicates(subset=[categorical_var], inplace = False)[categorical_var].to_list()
        for category in categorical_list:
            cat_list = df[numerical_var].loc[df[categorical_var] == category]
            sns.kdeplot(cat_list, fill = True, label = category)
            plt.legend()
        plt.show()
    def compare_histograms(self, categorical_var, numerical_var):
        categorical_list = self.data.drop_duplicates(subset=[categorical_var], inplace = False)[categorical_var].to_list()
        figure, axis = plt.subplots(1, len(categorical_list), sharey = True)
        for i in range(len(categorical_list)):
            cat_list = df[numerical_var].loc[df[categorical_var] == categorical_list[i]]
            axis[i].hist(cat_list, color='skyblue', edgecolor='black')
            axis[i].set_title(f'Histogram for {categorical_list[i]}')
        plt.show()


                
if __name__ == '__main__':
    FL = FileLoader()
    YF = YoungestFellah()
    PBS = ProportionBySport()
    HMM = HowManyMedals()
    STD = SpatioTemporalData()
    HMMBC = HowManyMedalsByCountry()
    MPL = MyPlotLib()

    path = "athlete_events.csv"
    n = -2
    year = 2004
    sport = 'Tennis'
    gender = 'F'
    name =  'Kjetil Andr Aamodt'
    location = 'Athina'
    country = 'France'
    features = ['Height', 'Weight']
    df = FL.load(path)
    #young_man = df.loc[df["Year"] == 1992].loc[df["Sex"] == "M"].nsmallest(1, 'Age')
    #print((young_man['Age'].to_list()[0]))
    #print(df[df["Year"] == 1992][df["Sex"] == "M"])
    #print(YF.youngest_fellah(df, year))
    #print(PBS.proportion_by_sport(df, year, sport, gender))
    #dic = HMM.how_many_medals(df, name)
    #for line in dic:
        #print(f"{line}: {dic[line]}")
    #print(STD.when(location))
    #print(STD.where(year))
    #dic = HMMBC.how_many_medals_by_country(df, country)
    #for line in dic:
        #print(f"{line}: {dic[line]}")
    #MPL.histogram(df, features)
    #MPL.density(df, features)
    MPL.pair_plot(df, features)
    #MPL.box_plot(df, features)
    #categorical_var = 'Sex'
    #numerical_var = 'Weight'
    #K = Komparator(df)
    #K.compare_box_plots(categorical_var, numerical_var)
    #K.density(categorical_var, numerical_var)
    #K.compare_histograms(categorical_var, numerical_var)
