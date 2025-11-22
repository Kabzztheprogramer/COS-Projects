#ifndef DYNAMICARRAYS_CPP
#define DYNAMICARRAYS_CPP

#include "DynamicArrays.h"

#endif

#include <iostream>


void createArray( int**& array,int*& numColumns, int& numRows, std::string input){
    int len = 0 ; 
    numRows = 1 ;
    int NL = 0;
    int *arrnum = new int [100];
      while(input[len]!= '\0'){
        ++len;
        if (input[len]=='|'){
            ++numRows;
        }  
    }

    numColumns = new int [numRows];
    len = 0 ;
    int columns = 0 ;
 
    for (int i = 0 ; i < numRows ; i++){
           while(input[len]!= '\0' && input[len]!='|'){
            if (input[len]!=','){
                ++columns;
               std:: stringstream snum;
                snum << input[len];
                snum >> arrnum[NL];
                ++NL;
        }  
            ++len;
           }
           
        *(numColumns+i)= columns;
        if (input[len] != '\0'){
            ++len;
            columns = 0;
        }
    
      
    }
    //initializing the array
    array = new int* [numRows];
    for (int i = 0 ; i < numRows ; i++){
       *(array + i) = new int [*(numColumns + i)] ;
    }
    // adding the value to the array
    NL = 0;
    for (int i = 0; i < numRows;i++){
        for( int j = 0; j < numColumns[i];j++){
            array[i][j] = arrnum[NL];
            ++NL;
        };
    }
 delete[] arrnum;
 arrnum = NULL;

};

std::string printArrayStructure(int**& array, int*& numColumns, int& numRows){

   std:: string ST = "numRows : ";
   std:: string snum ;
   std:: stringstream intTostr;
    intTostr << numRows;
    intTostr >> snum;
    ST += snum ;

    for (int i = 0; i <  numRows; i++){
        snum = "";
        ST +=  '\n';
        std:: stringstream ri;
        ri << i;
        ri >> snum;
        ST += "row["+ snum + "] : ";
        snum = "";
        std:: stringstream ci;
        ci<< numColumns[i];
        ci>> snum;
        ST += snum ;
    }
    return ST;
};

std::string printArray(int**& array, int*& numColumns, int& numRows){
    std::string strArr;
    std::string snum ;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns[i]; j++) {
            snum = "";
            std:: stringstream ci;
            ci<< array[i][j];
            ci>> snum;
            if(numColumns[i]-1 == j){
                strArr += snum ;
            }else {
                strArr += snum +  ',';
            }
        }
    if(i != numRows-1){
        strArr+= '\n';
    }
    
    }
    return strArr;
};

void destroyArray(int**& array, int*& numColumns, int& numRows){

    for (int i = 0 ; i < numRows ; i++){
        delete [] array[i] ;
    }
    delete [] array;
    delete [] numColumns;
    array = NULL ;
    numColumns = NULL ;
    numRows = 0 ;

};


void addRow(int**& array, int*& numColumns, int& numRows){

//creating the new var
    int newRows = numRows+1;
    int **arrNew = new int* [newRows];
    int *colNew = new int [newRows];
    
//copying the values to new var
    for (int i = 0; i < numRows;i++){
        arrNew[i] = new int [numColumns[i]] ;
        colNew[i] = numColumns[i];

        for( int j = 0; j < numColumns[i];j++){
            arrNew[i][j] = array[i][j];
        };
    }

 //adding the new row 
    colNew[numRows] = 0;
    arrNew[numRows]= new int [0];
   
//Destroy the old array
    destroyArray(array,numColumns,numRows);

//Update pointers
    array = arrNew;
    numColumns = colNew;
    numRows = newRows;
    
};

void addValueToRow(int**& array, int*& numColumns, int& numRows, int rowNumber, int value){
//check if the row is vaild 
    if(rowNumber <= numRows){
    //updating the number of columns in the array 
        numColumns[rowNumber]= numColumns[rowNumber] +1 ;
    // creating & copying the values to new arr
       int  *arrRow = new int [numColumns[rowNumber]];

       for ( int i = 0 ; i < numColumns[rowNumber]-1; i++){
            arrRow[i] = array[rowNumber][i];
       }
    //adding the new values
       arrRow[numColumns[rowNumber]-1]= value;
    //Update pointers
       delete [] array[rowNumber] ;
       array[rowNumber] = arrRow;

    }
};

void removeRow(int**& array, int*& numColumns, int& numRows, int rowNumber){

    if(rowNumber <= numRows){
   //creating the new var
        int newRows = numRows-1;
        int **arrNew = new int* [newRows];
        int *colNew = new int [newRows];
    //copying the values to new var
        int bs= 0 ;
        for (int i = 0; i < numRows;i++){
            //checking it's the row we need to remove
            if (i == rowNumber){

                ++bs;
            }else{
            arrNew[i-bs] = new int [numColumns[i]] ;
            colNew[i-bs] = numColumns[i];

            for( int j = 0; j < numColumns[i];j++){
                arrNew[i-bs][j] = array[i][j];
            };
            };
        }

   
//Destroy the old array
    destroyArray(array,numColumns,numRows);

//Update pointers
    array = arrNew;
    numColumns = colNew;
    numRows = newRows;
    };

};
void removeValueFromRow(int**& array, int*& numColumns, int& numRows, int rowNumber, int value){
    //checking if the row is vaild 
    if(rowNumber <= numRows){
    //checking the amount of times the value appears in the row

        int Collen =0 ;
        for (int i = 0; i < numColumns[rowNumber]; i++){
           if (array[rowNumber][i] != value){
            ++Collen;
           }
        }
    // creating & copying the values to new arr
       int  *arrRow = new int [Collen];
       int bs = 0;
       for ( int i = 0 ; i < numColumns[rowNumber]; i++){
            if (array[rowNumber][i] != value){
                arrRow[i-bs] = array[rowNumber][i];
            }else{
                ++bs;
            }
    //Update pointers
       delete [] array[rowNumber] ;
       array[rowNumber] = arrRow;  
       numColumns[rowNumber] = Collen;
         

        }
    }
};


int rowSum(int**& array, int*& numColumns, int& numRows, int rowNumber){
    //checking if the row is vaild 
    if(rowNumber >= 0 || rowNumber <= numRows  ||numColumns[rowNumber]== 0){
        return -1;
    }else{
    //checking the amount of times the value appears in the row
        int total = 0 ;
        for (int i = 0; i < numColumns[rowNumber]; i++){
           total += array[rowNumber][i];

}
return total;
}

};

float rowAvg(int**& array, int*& numColumns, int& numRows, int rowNumber){
    //checking if the row is vaild 
     if(rowNumber >= 0 || rowNumber <= numRows  ||numColumns[rowNumber]==0){
        return -1;
    }else{
    //checking the amount of times the value appears in the row
    float totalnum =numColumns[rowNumber];
    return rowSum(array,numColumns,numRows,rowNumber)/totalnum;
}
}

int rowMax(int**& array, int*& numColumns, int& numRows, int rowNumber){
    //checking if the row is vaild 
     if(rowNumber >= 0 || rowNumber <= numRows  ||numColumns[rowNumber] == 0){
        return -1;
    }else{
    //checking the amount of times the value appears in the row
        int max ;
        for (int i = 0; i < numColumns[rowNumber]; i++){
           if (array[rowNumber][i] > max ){
            max = array[rowNumber][i];
           }

}
return max;
}
};

int rowMin(int**& array, int*& numColumns, int& numRows, int rowNumber){
    //checking if the row is vaild 
    if(rowNumber >= 0 || rowNumber <= numRows  ||numColumns[rowNumber] ==0){
        return -1;
    }else{
    //checking the amount of times the value appears in the row
        int min =array[rowNumber][0];
        for (int i = 0; i < numColumns[rowNumber]; i++){
           if (array[rowNumber][i] < min ){
            min= array[rowNumber][i];
           }

}
return min;

}

};


