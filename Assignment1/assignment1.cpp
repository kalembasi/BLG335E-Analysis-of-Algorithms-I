#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
#include <chrono>

using namespace std;

void printFile(vector<float> &id, vector<float> &arr, string filename, int size){
    fstream file;
    file.open(filename, ios:: out | ios::app);
    for(int i = 0; i < size; i++){
        file << id[i] << "," << arr[i] << endl;
    }

    file.close();
}

int partition(vector<float> &arr, vector<float> &id, int low, int high, int &numberOfPartitions){

    numberOfPartitions++;

    if(high > low ){
        int i = low;
        int j = low;
        float pivot = arr[high];
        float temp = 0;
    
        while(arr[i] <= pivot && arr[j] <= pivot ){      
            
            if(i < high && j <high){
                j++;
                i++;
            }
            else{
                break;
            }   
        }
        
        while(arr[j] > pivot ){
            if(j < high){
                j++;
            }
            else{
                break;
            }        

            temp = arr[i];  //swap avg rating
            arr[i] = arr[j];
            arr[j] = temp;

            temp = id[i];   //swap id
            id[i] = id[j];
            id[j] = temp;          

            if(arr[i] <= pivot){
                if(i < high){
                    i++;
                }
                else{
                    break;
                } 
            }
        }
     
        temp = 0;

        if(j == high){
            temp = arr[i];  //swap avg rating
            arr[i] = arr[high];
            arr[high] = temp;  

            temp = id[i];   //swap id
            id[i] = id[j];
            id[j] = temp; 
        }
        return i; 
    }
}

void quickSort(vector<float> &arr, vector<float> &id, int low, int high, int &numberOfPartitions, int &numberOfSwaps){

    numberOfSwaps++;

    if(high > low ){

        int p = partition(arr, id, low, high, numberOfPartitions);
        quickSort(arr, id, low, p-1, numberOfPartitions, numberOfSwaps);
        quickSort(arr, id, p, high, numberOfPartitions, numberOfSwaps);
    }
}

int main(){

    vector<vector<string>> twoDimensionArr;
    vector<string> row;
    string line = "";
    string word = "";   

    twoDimensionArr.clear();
    row.clear();

    ifstream file;
    file.open("books.csv");

    while(getline(file, line)){
        stringstream str(line);
        while(getline(str, word, ',')){     //seperate words with coma in line
            row.push_back(word);            //push words into row array
        }
        twoDimensionArr.push_back(row);     //push row into 2d array
        row.clear();
    }

    vector<float> avgArr;
    vector<float> BookID;

    for(int i = 1; i < twoDimensionArr.size(); i++){
        float avg = 0;
        avg = stof(twoDimensionArr[i][3]);  //convert string to float
        avgArr.push_back(avg);

        float id = 0;
        id = stof(twoDimensionArr[i][0]);
        BookID.push_back(id);
        
        //cout << id << " " << avg << endl; 
    }

    float low = 0;
    float high = avgArr.size()-1;

    int numberOfPartitions = 0;
    int numberOfSwaps = 0;

    auto begin = std::chrono::high_resolution_clock::now();
    quickSort(avgArr, BookID, low, high, numberOfPartitions, numberOfSwaps);
    auto end = std::chrono::high_resolution_clock::now();
    //auto timeElapsed = chrono::duration_cast<chrono::microseconds>(end - begin);

    cout << "Time elapsed (microseconds): " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;
    cout << "Number of partitions: " << numberOfPartitions << endl;
    cout << "Number of swaps: " << numberOfSwaps << endl;
    
    for(int i = 0; i < avgArr.size()-1; i++){

        //cout << BookID[i] << "\t" << avgArr[i] << endl;
    }

    printFile(BookID, avgArr, "sorted_books.txt", avgArr.size()-1);
    //cout << BookID.size() << endl;


    return 0;
}