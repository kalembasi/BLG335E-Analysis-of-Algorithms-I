//Ömer Malik Kalembaşı
//150180112
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
#include <cmath>
#include <chrono>
#include <stdio.h>


using namespace std;
int numberOfCalls = 0;

class sample{
    public:
        string date = "";
        string time = "";
        float gap = 0;
        float grp = 0;
        float v = 0;
        float gi = 0;
};

void swap(sample *a, sample *b){
    sample temp = *b;
    *b = *a;
    *a = temp;
}

//functions for gap
void heapifyGap(vector<sample> &hT, int i, int size){
  
    //int size = hT.size();
    int max = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
  
    if(leftChild < size && hT[leftChild].gap > hT[max].gap)
        max = leftChild;
    if(rightChild < size && hT[rightChild].gap > hT[max].gap)
        max = rightChild;
    if(max != i){
        swap(&hT[i], &hT[max]);
        heapifyGap(hT, max, size);
    }
    numberOfCalls++;
}
  
void heapSortGap(vector<sample> &hT) {   //main function to do heap sort
    int size = hT.size();

    for (int i = hT.size() / 2 - 1; i >= 0; i--){    //build max heap
        heapifyGap(hT, i, size);
    }

    for (int i = hT.size() - 1; i >= 0; i--){   //heap sort
        swap(hT[0], hT[i]);
        size --;
        heapifyGap(hT, 0, size);    //heapify root element to get highest element at root again
    }

    //printHeapGap(hT);
    numberOfCalls++;
}

float calculateMeanGap(vector<sample>);
float calculateStandardDevGap(vector<sample>);
float findMinValueGap(vector<sample>);
float findMaxValueGap(vector<sample>);
float findMedianGap(vector<sample>);
float calculateFirstQuadrantGap(vector<sample>);
float calculateThirdQuadrantGap(vector<sample>);

//functions for grp
void heapifyGrp(vector<sample> &hT, int i, int size){
  
    //int size = hT.size();
    int max = i;   
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
  
    if(leftChild < size && hT[leftChild].grp > hT[max].grp)
        max = leftChild;
    if(rightChild < size && hT[rightChild].grp > hT[max].grp)
        max = rightChild;
    if(max != i){
        swap(&hT[i], &hT[max]);
        heapifyGrp(hT, max, size);
    }
    numberOfCalls++;
}
 
void heapSortGrp(vector<sample> &hT) {   //main function to do heap sort
    int size = hT.size();

    for (int i = hT.size() / 2 - 1; i >= 0; i--){    //build max heap
        heapifyGrp(hT, i, size);
    }

    for (int i = hT.size() - 1; i >= 0; i--){   //heap sort
        swap(hT[0], hT[i]);
        size --;
        heapifyGrp(hT, 0, size);    //heapify root element to get highest element at root again
    }

    //printHeapGrp(hT);
    numberOfCalls++;
}

float calculateMeanGrp(vector<sample>);
float calculateStandardDevGrp(vector<sample>);
float findMinValueGrp(vector<sample>);
float findMaxValueGrp(vector<sample>);
float findMedianGrp(vector<sample>);
float calculateFirstQuadrantGrp(vector<sample>);
float calculateThirdQuadrantGrp(vector<sample>);

//functions for v
void heapifyV(vector<sample> &hT, int i, int size){
  
    //int size = hT.size();
    int max = i;  
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
  
    if(leftChild < size && hT[leftChild].v > hT[max].v)
        max = leftChild;
    if(rightChild < size && hT[rightChild].v > hT[max].v)
        max = rightChild;
    if(max != i){
        swap(&hT[i], &hT[max]);
        heapifyV(hT, max, size);
    }
    
    numberOfCalls++;
}

void heapSortV(vector<sample> &hT) {   //main function to do heap sort
    int size = hT.size();

    for (int i = hT.size() / 2 - 1; i >= 0; i--){    //build max heap
        heapifyV(hT, i, size);
    }

    for (int i = hT.size() - 1; i >= 0; i--){   //heap sort
        swap(hT[0], hT[i]);
        size --;
        heapifyV(hT, 0, size);    //heapify root element to get highest element at root again
    }

    //printHeapV(hT);
    numberOfCalls++;
}

float calculateMeanV(vector<sample>);
float calculateStandardDevV(vector<sample>);
float findMinValueV(vector<sample>);
float findMaxValueV(vector<sample>);
float findMedianV(vector<sample>);
float calculateFirstQuadrantV(vector<sample>);
float calculateThirdQuadrantV(vector<sample>);

//functions for gi
void heapifyGi(vector<sample> &hT, int i, int size){
  
    //int size = hT.size();
    int max = i;    
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
  
    if(leftChild < size && hT[leftChild].gi > hT[max].gi)
        max = leftChild;
    if(rightChild < size && hT[rightChild].gi > hT[max].gi)
        max = rightChild;
    if(max != i){
        swap(&hT[i], &hT[max]);
        heapifyGi(hT, max, size);
    }

    numberOfCalls++;
}

void heapSortGi(vector<sample> &hT) {   //main function to do heap sort
    int size = hT.size();

    for (int i = hT.size() / 2 - 1; i >= 0; i--){    //build max heap
        heapifyGi(hT, i, size);
    }

    for (int i = hT.size() - 1; i >= 0; i--){   //heap sort
        swap(hT[0], hT[i]);
        size --;
        heapifyGi(hT, 0, size);    //heapify root element to get highest element at root again
    }

    //printHeapGi(hT);
    numberOfCalls++;
}

float calculateMeanGi(vector<sample>);
float calculateStandardDevGi(vector<sample>);
float findMinValueGi(vector<sample>);
float findMaxValueGi(vector<sample>);
float findMedianGi(vector<sample>);
float calculateFirstQuadrantGi(vector<sample>);
float calculateThirdQuadrantGi(vector<sample>);

void insert(vector<sample> &hT, sample newSample){
    int size = hT.size();
    if(size == 0){
        hT.push_back(newSample);
    }
    
    else{
        hT.push_back(newSample);
        for (int i = size / 2 - 1; i >= 0; i--){
            heapifyGap(hT, i, hT.size());
        }
    }
}

int main(){

    auto begin = std::chrono::high_resolution_clock::now();

    vector<string> estimators; 
    string line = "";

    ifstream file;  //open file
    file.open("input.txt");
    
    getline(file, line);    //get number of estimators
    int numberOfEstimators = stoi(line);
    //cout << numberOfEstimators << endl;

    for(int i=0; i<numberOfEstimators; i++){    //store estimators into vector
        getline(file, line);
        estimators.push_back(line);
    }
    
    getline(file, line);    //skip the empty line
    
    string numberOfLines = "";
    string feature = "";

    getline(file, line);
    stringstream str(line);
    getline(str, numberOfLines, ',');
    getline(str, feature);
    //cout << numberOfLines << ", " << feature << endl;

    sample sampleFeature;
    string word = "";

    vector<sample> heapTree;
    
    int addCount = 0;
    string startingDate = "";
    string startingTime = "";
    string latestRetrivedDay = "";
    string latestRetrivedTime = "";
    
    while(getline(file, line)){

        if(line == "add"){
            //cout << "add" << endl;

            getline(file, line);
            stringstream str(line);
            
            getline(str, sampleFeature.date, ',');   //store date into class
            getline(str, sampleFeature.time, ',');   //store time into class
            
            getline(str, word, ',');
            sampleFeature.gap = stof(word);     //store gap into class

            getline(str, word, ',');
            sampleFeature.grp = stof(word);     //store grp into class

            getline(str, word, ',');
            sampleFeature.v = stof(word);     //store v into class

            getline(str, word, ',');
            sampleFeature.gi = stof(word);     //store gi into class

            //heapTree.push_back(sampleFeature);
            insert(heapTree, sampleFeature);    //push class into heap
            //heapSortGap(heapTree);
            if(addCount == 0){
                startingDate = sampleFeature.date;  
                startingTime = sampleFeature.time;
            }

            latestRetrivedDay = sampleFeature.date;
            latestRetrivedTime = sampleFeature.time;

            addCount++;
        }
        
        else if(line == "print"){
            //cout << "print" << endl;
            heapSortGap(heapTree);  //heapify
            cout << startingDate;
            cout << "," << startingTime;
            cout << "," << latestRetrivedDay;
            cout << "," << latestRetrivedTime;

            if(feature == "gap"){
                for(int i=0; i<estimators.size(); i++){
                    if(estimators[i] == "mean"){
                        cout << "," << calculateMeanGap(heapTree);
                    }
                    if(estimators[i] == "std"){
                        cout << "," << calculateStandardDevGap(heapTree);
                    }
                    if(estimators[i] == "min"){
                        cout << "," << findMinValueGap(heapTree);
                    }
                    if(estimators[i] == "firstq"){
                        cout << "," << calculateFirstQuadrantGap(heapTree);
                    }
                    if(estimators[i] == "median"){
                        cout << "," << findMedianGap(heapTree);
                    }
                    if(estimators[i] == "thirdq"){
                        cout << "," << calculateThirdQuadrantGap(heapTree);
                    }
                    if(estimators[i] == "max"){
                        cout << "," << findMaxValueGap(heapTree);
                    }    
                }   
                cout << endl; 
            }
            if(feature == "grp"){
                for(int i=0; i<estimators.size(); i++){
                    if(estimators[i] == "mean"){
                        cout << "," << calculateMeanGrp(heapTree);
                    }
                    if(estimators[i] == "std"){
                        cout << "," << calculateStandardDevGrp(heapTree);
                    }
                    if(estimators[i] == "min"){
                        cout << "," << findMinValueGrp(heapTree);
                    }
                    if(estimators[i] == "firstq"){
                        cout << "," << calculateFirstQuadrantGrp(heapTree);
                    }
                    if(estimators[i] == "median"){
                        cout << "," << findMedianGrp(heapTree);
                    }
                    if(estimators[i] == "thirdq"){
                        cout << "," << calculateThirdQuadrantGrp(heapTree);
                    }
                    if(estimators[i] == "max"){
                        cout << "," << findMaxValueGrp(heapTree);
                    }    
                }   
                cout << endl; 
            }
            if(feature == "v"){
                for(int i=0; i<estimators.size(); i++){
                    if(estimators[i] == "mean"){
                        cout << "," << calculateMeanV(heapTree);
                    }
                    if(estimators[i] == "std"){
                        cout << "," << calculateStandardDevV(heapTree);
                    }
                    if(estimators[i] == "min"){
                        cout << "," << findMinValueV(heapTree);
                    }
                    if(estimators[i] == "firstq"){
                        cout << "," << calculateFirstQuadrantV(heapTree);
                    }
                    if(estimators[i] == "median"){
                        cout << "," << findMedianV(heapTree);
                    }
                    if(estimators[i] == "thirdq"){
                        cout << "," << calculateThirdQuadrantV(heapTree);
                    }
                    if(estimators[i] == "max"){
                        cout << "," << findMaxValueV(heapTree);
                    }    
                }   
                cout << endl; 
            }
            if(feature == "gi"){
                for(int i=0; i<estimators.size(); i++){
                    if(estimators[i] == "mean"){
                        cout << "," << calculateMeanGi(heapTree);
                    }
                    if(estimators[i] == "std"){
                        cout << "," << calculateStandardDevGi(heapTree);
                    }
                    if(estimators[i] == "min"){
                        cout << "," << findMinValueGi(heapTree);
                    }
                    if(estimators[i] == "firstq"){
                        cout << "," << calculateFirstQuadrantGi(heapTree);
                    }
                    if(estimators[i] == "median"){
                        cout << "," << findMedianGi(heapTree);
                    }
                    if(estimators[i] == "thirdq"){
                        cout << "," << calculateThirdQuadrantGi(heapTree);
                    }
                    if(estimators[i] == "max"){
                        cout << "," << findMaxValueGi(heapTree);
                    }    
                }   
                cout << endl; 
            }
                                    
        }
        
        else if(line == ""){break;}

        else{
            //do nothing
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    cout <<"Time elapsed (microseconds): " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;
    cout <<"Number of calls the data structure methods: " << numberOfCalls << endl;
    return 0;
}

//calculate functions for gap
float calculateMeanGap(vector<sample> hT){   //function calculates the mean of gaps
    float mean = 0;
    for(int i=0; i<hT.size(); i++){
        mean += hT[i].gap;
    }
    return mean /= hT.size();
}

float calculateStandardDevGap(vector<sample> hT){   //function calculates the standard deviation of gaps
    float standardDev = 0;
    for(int i=0; i<hT.size(); ++i){
        standardDev += pow(hT[i].gap - calculateMeanGap(hT), 2);
    }
    
    return sqrt(standardDev / (hT.size()-1));
}

float findMinValueGap(vector<sample> hT){   //function finds the min gap value
    float minValue = hT[0].gap;
    for(int i=0; i<hT.size(); i++){
        if(hT[i].gap < minValue){
            minValue = hT[i].gap;
        }
    }

    return minValue;
}

float findMaxValueGap(vector<sample> hT){return hT[hT.size()-1].gap;} //funciton finds the max gap value which is root

float findMedianGap(vector<sample> hT){ //function finds median
    //heapSortGap(hT);
    if(hT.size() % 2 == 1){
        return hT[hT.size() / 2].gap;
    }
    else if(hT.size() % 2 == 0){
        return (hT[(hT.size()-1)/2].gap + hT[hT.size()/2].gap) / 2 ;
    }else{return 0;}
}

float calculateFirstQuadrantGap(vector<sample> hT){ //function calculates first quadrant
    float firstQuadrant = 0.25 * (hT.size() - 1);
    int lower = (int)firstQuadrant;

    return hT[lower].gap + (firstQuadrant-lower)*(hT[lower + 1].gap - hT[lower].gap);
}

float calculateThirdQuadrantGap(vector<sample> hT){ //function calculates third quadrant
    float firstQuadrant = 0.75 * (hT.size() - 1);
    int lower = (int)firstQuadrant;

    return hT[lower].gap + (firstQuadrant-lower)*(hT[lower + 1].gap - hT[lower].gap);
}

//calculate functions for grp
float calculateMeanGrp(vector<sample> hT){   //function calculates the mean of grps
    float mean = 0;
    for(int i=0; i<hT.size(); i++){
        mean += hT[i].grp;
    }
    return mean /= hT.size();
}

float calculateStandardDevGrp(vector<sample> hT){   //function calculates the standard deviation of grps
    float standardDev = 0;
    for(int i=0; i<hT.size(); ++i){
        standardDev += pow(hT[i].grp - calculateMeanGrp(hT), 2);
    }
    
    return sqrt(standardDev / (hT.size()-1));
}

float findMinValueGrp(vector<sample> hT){   //function finds the min grp value
    float minValue = hT[0].grp;
    for(int i=0; i<hT.size(); i++){
        if(hT[i].grp < minValue){
            minValue = hT[i].grp;
        }
    }

    return minValue;
}

float findMaxValueGrp(vector<sample> hT){return hT[hT.size()-1].grp;} //funciton finds the max gap value which is root

float findMedianGrp(vector<sample> hT){ //function finds median
    //heapSortGrp(hT);
    if(hT.size() % 2 == 1){
        return hT[hT.size() / 2].grp;
    }
    else if(hT.size() % 2 == 0){
        return (hT[(hT.size()-1)/2].grp + hT[hT.size()/2].grp) / 2 ;
    }else{return 0;}
}

float calculateFirstQuadrantGrp(vector<sample> hT){ //function calculates first quadrant
    float firstQuadrant = 0.25 * (hT.size() - 1);
    int lower = (int)firstQuadrant;

    return hT[lower].grp + (firstQuadrant-lower)*(hT[lower + 1].grp - hT[lower].grp);
}

float calculateThirdQuadrantGrp(vector<sample> hT){ //function calculates third quadrant
    float firstQuadrant = 0.75 * (hT.size() - 1);
    int lower = (int)firstQuadrant;

    return hT[lower].grp + (firstQuadrant-lower)*(hT[lower + 1].grp - hT[lower].grp);
}

//calculate functions for v
float calculateMeanV(vector<sample> hT){   //function calculates the mean of vs
    float mean = 0;
    for(int i=0; i<hT.size(); i++){
        mean += hT[i].v;
    }
    return mean /= hT.size();
}

float calculateStandardDevV(vector<sample> hT){   //function calculates the standard deviation of vs
    float standardDev = 0;
    for(int i=0; i<hT.size(); ++i){
        standardDev += pow(hT[i].v - calculateMeanV(hT), 2);
    }
    
    return sqrt(standardDev / (hT.size()-1));
}

float findMinValueV(vector<sample> hT){   //function finds the min v value
    float minValue = hT[0].v;
    for(int i=0; i<hT.size(); i++){
        if(hT[i].v < minValue){
            minValue = hT[i].v;
        }
    }

    return minValue;
}

float findMaxValueV(vector<sample> hT){return hT[hT.size()-1].v;} //funciton finds the max v value which is root

float findMedianV(vector<sample> hT){ //function finds median
    //heapSortV(hT);
    if(hT.size() % 2 == 1){
        return hT[hT.size() / 2].v;
    }
    else if(hT.size() % 2 == 0){
        return (hT[(hT.size()-1)/2].v + hT[hT.size()/2].v) / 2 ;
    }else{return 0;}
}

float calculateFirstQuadrantV(vector<sample> hT){ //function calculates first quadrant
    float firstQuadrant = 0.25 * (hT.size() - 1);
    int lower = (int)firstQuadrant;

    return hT[lower].v + (firstQuadrant-lower)*(hT[lower + 1].v - hT[lower].v);
}

float calculateThirdQuadrantV(vector<sample> hT){ //function calculates third quadrant
    float firstQuadrant = 0.75 * (hT.size() - 1);
    int lower = (int)firstQuadrant;

    return hT[lower].v + (firstQuadrant-lower)*(hT[lower + 1].v - hT[lower].v);
}

//calculate functions for gi
float calculateMeanGi(vector<sample> hT){   //function calculates the mean of gis
    float mean = 0;
    for(int i=0; i<hT.size(); i++){
        mean += hT[i].gi;
    }
    return mean /= hT.size();
}

float calculateStandardDevGi(vector<sample> hT){   //function calculates the standard deviation of gis
    float standardDev = 0;
    for(int i=0; i<hT.size(); ++i){
        standardDev += pow(hT[i].gi - calculateMeanV(hT), 2);
    }
    
    return sqrt(standardDev / (hT.size()-1));
}

float findMinValueGi(vector<sample> hT){   //function finds the min gi value
    float minValue = hT[0].gi;
    for(int i=0; i<hT.size(); i++){
        if(hT[i].gi < minValue){
            minValue = hT[i].gi;
        }
    }

    return minValue;
}

float findMaxValueGi(vector<sample> hT){return hT[hT.size()-1].gi;} //funciton finds the max gi value which is root

float findMedianGi(vector<sample> hT){ //function finds median
    //heapSortGi(hT);
    if(hT.size() % 2 == 1){
        return hT[hT.size() / 2].gi;
    }
    else if(hT.size() % 2 == 0){
        return (hT[(hT.size()-1)/2].gi + hT[hT.size()/2].gi) / 2 ;
    }else{return 0;}
}

float calculateFirstQuadrantGi(vector<sample> hT){ //function calculates first quadrant
    float firstQuadrant = 0.25 * (hT.size() - 1);
    int lower = (int)firstQuadrant;

    return hT[lower].gi + (firstQuadrant-lower)*(hT[lower + 1].gi - hT[lower].gi);
}

float calculateThirdQuadrantGi(vector<sample> hT){ //function calculates third quadrant
    float firstQuadrant = 0.75 * (hT.size() - 1);
    int lower = (int)firstQuadrant;

    return hT[lower].gi + (firstQuadrant-lower)*(hT[lower + 1].gi - hT[lower].gi);
}
