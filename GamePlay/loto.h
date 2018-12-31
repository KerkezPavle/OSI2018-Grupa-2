#ifndef LOTO_LOTO_H
#define LOTO_LOTO_H

#define NUMBER 7
#define RANDNUMBER 20
#include <random>


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
    std::cout<<"Unesite vasu kombinaciju:"<<std::endl;
    int tmp=0;
    for(int i=0;i<NUMBER;i++)
    {
        do
        {
            std::cout<<"\t"<<i+1<<". broj--->";
            std::cin>>tmp;
        }while(tmp<=0 || tmp>45 || isInArray(combinationArray,NUMBER,tmp) );
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
void lotoGame(void)
{
    int userScore = 0;
    int *userCombination = new int[NUMBER];
    int *randomCombination = new int[RANDNUMBER];
    loadUserCombination(userCombination);
    printCombination(userCombination,NUMBER);
    do{
        generateRandomCombination(randomCombination);
        userScore = calculateScore(userCombination,randomCombination);
    }while(userScore>60);
    printCombination(randomCombination,RANDNUMBER);

    std::cout<<std::endl;
    std::cout<<"OSVOJENI BODOVI: "<< userScore << std::endl;

    std::cout<<std::endl;
    delete[] userCombination;
    delete[] randomCombination;
}


#endif //LOTO_LOTO_H
