#ifndef LOTO_LOTO_H
#define LOTO_LOTO_H

#define NUMBER 7
#define RANDNUMBER 20
#include <random>
#include <iostream>


bool isInArray(int *array,int size, int key)
{
    for(int i=0;i<size;i++)
        if(array[i]==key)
            return true;
    return false;
}
void printCombination(int *array, int size)
{
    std::cout<<"[ ";
    for(int i=0;i<size;i++)
        std::cout<<array[i]<<" ";
    std::cout<<"]"<<std::endl;
}
void loadUserCombination(int *combinationArray)
{
    std::cout<<"Unesite vašu kombinaciju:"<<std::endl;
    int tmp=-1;
    int errorFlag=0;
    for(int i=0;i<NUMBER;i++)
    {
        do
        {
            std::cout<<"\t"<<i+1<<". broj--->";
            char c ;
            if( !( std::cin >>tmp ) || ( std::cin.get(c) && !std::isspace(c) ) )
            {
                std::cin.clear();
                std::cin.ignore( 500, '\n' );
                tmp = -1 ;
            }
        }while(tmp<0 || tmp>45 || isInArray(combinationArray,NUMBER,tmp));
        combinationArray[i]=tmp;
    }
}
void generateRandomCombination(int *randomCombination)
{
    std::random_device randomGenerator;
    for (int i = 0; i < RANDNUMBER; ++i) {
        int tmp;
        do
        {
            tmp =  1 + abs((int) randomGenerator() % 45);
        }while(isInArray(randomCombination,RANDNUMBER,tmp));
        randomCombination[i]=tmp;
    }
}
int calculateScore(int *userCombination, int *randomCombination)
{
    int finalScore = 0;
    int counter = 1;
    for(int i=0;i<NUMBER;i++)
        if(isInArray(randomCombination,RANDNUMBER,userCombination[i]))
        {
            finalScore+=counter*10;
            counter++;
        }
    return finalScore;
}
int lotoGame(int currentNUmberOfPoints, double inputPercentage)
{
    int userScore = 0;
    int *userCombination = new int[NUMBER];
    int *randomCombination = new int[RANDNUMBER];
    double factor =(inputPercentage/100)*currentNUmberOfPoints;
    loadUserCombination(userCombination);
    do{
        generateRandomCombination(randomCombination);
        userScore = calculateScore(userCombination,randomCombination);
    }while(userScore>factor);

    std::cout<<"-------------------------------------------------------------"<<std::endl;
    std::cout<<"|                           BINGO                           |"<<std::endl;
    std::cout<<"-------------------------------------------------------------"<<std::endl;
    std::cout<<"TRENUTNI BROJ BODOVA: ";std::cout<<currentNUmberOfPoints<<std::endl;
    std::cout<<"-------------------------------------------------------------"<<std::endl;
    std::cout<<"VAŠA KOBINACIJA: "; printCombination(userCombination,NUMBER);
    std::cout<<"-------------------------------------------------------------"<<std::endl;
    std::cout<<"DOBITNA KOBINACIJA: "<<std::endl; printCombination(randomCombination,RANDNUMBER);
    std::cout<<"-------------------------------------------------------------"<<std::endl;
    std::cout<<"OSVOJENI BODOVI: "<< userScore << std::endl;
    std::cout<<"-------------------------------------------------------------"<<std::endl;
    std::cout<<"UKUPAN BROJ BODOVA: "<< userScore + currentNUmberOfPoints << std::endl;
    std::cout<<"-------------------------------------------------------------"<<std::endl;
    std::cout<<"|                           KRAJ                            |"<<std::endl;
    std::cout<<"-------------------------------------------------------------"<<std::endl;
    delete[] userCombination;
    delete[] randomCombination;

    return currentNUmberOfPoints+userScore;
}


#endif //LOTO_LOTO_H
