

#include "avg_and_max.h"

double average(double array[], int size){
    double sum = 0;
    for(int i =0; i < size - 1; i++){
        sum += array[i];
    }
    return sum/size;
    
}

double max (double array[], int size){
    double max;
    for(int i =0; i < size ; i++){
        if(max < array[i])
            max = array[i];
    }
    return max;
    
}