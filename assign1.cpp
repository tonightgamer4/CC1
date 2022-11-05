
None selected

Skip to content
Using Gmail with screen readers
Conversations
0.29 GB of 15 GB used
Terms · Privacy · Program Policies
Last account activity: 11 minutes ago
Details
#include <bits/stdc++.h>
using namespace std;

struct result{
    int roll;
    string name;
    float SGPA;
}details;


void printDetails(result details[],int n){
        for(int i = 0; i<n; i++){
        cout<<"Roll No. : "<<details[i].roll<<" Name : "<<details[i].name<<" SGPA : "<<details[i].SGPA<<endl;
    }
}

//c.Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
int partition(result *details, int s, int e){
    float pivot = details[s].SGPA;
    int count = 0;

    for(int i = s+1; i<=e; i++){
        if(details[i].SGPA>=pivot){
            count++;
        }
    }
    //placing pivot at right place
    int pivotIndex = s + count;

    swap(details[s].SGPA, details[pivotIndex].SGPA);
    swap(details[s].roll, details[pivotIndex].roll);
    swap(details[s].name, details[pivotIndex].name);

    int i = s, j = e;
    while(i<pivotIndex && j>pivotIndex){
        while(details[i].SGPA>pivot){
            i++;
        }

        while(details[j].SGPA < pivot){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(details[i].SGPA, details[j].SGPA);
            swap(details[i].roll, details[j].roll);
            swap(details[i].name, details[j].name);

        }
    }
    return pivotIndex;
}

void quickSort(result *details, int s, int e){
    //base case
    if(s>=e){
        return;
    }

    int p = partition(details, s, e);

    //sorting of left part
    quickSort(details, 0, p-1);
    quickSort(details, p+1, e);
}

void binarySearchName(result *details, int n, string str)
{   
    // cout<<"Searching for "<<str<<endl;
    if(n<=2){
        if( details[0].name == str){
            cout<<"Roll No. : "<<details[0].roll<<" Name : "<<details[0].name<<" SGPA : "<<details[0].SGPA<<endl;

        }else if ( details[1].name == str){
            cout<<"Roll No. : "<<details[1].roll<<" Name : "<<details[1].name<<" SGPA : "<<details[1].SGPA<<endl;

        }
    }

    int lo = 0, hi = n-1, mid;
    while(hi - lo > 1){
        mid = (hi + lo)/2;
        if(str >= details[mid].name){
            lo = mid;
        }else{
            hi = mid - 1;
        }

        if( details[lo].name == str){
            cout<<"Roll No. : "<<details[lo].roll<<" Name : "<<details[lo].name<<" SGPA : "<<details[lo].SGPA<<endl;
            break;
        }else if ( details[hi].name == str){
            cout<<"Roll No. : "<<details[hi].roll<<" Name : "<<details[hi].name<<" SGPA : "<<details[hi].SGPA<<endl;
            break;
        }
        
    }
    // if(details[lo].name != str || details[hi].name != str){
    //     cout<<"Student with name "<<str<<" is not present"<<endl;
    //     }
    
}

void bubbleSort(result details[], int n){
    for(int i = 0; i<=n-1; i++){
    //for round 1 to n-1
        for(int j=0; j<n-1-i; j++){
            if(details[j].roll > details[j+1].roll){
                swap(details[j].roll, details[j+1].roll);
                swap(details[j].name, details[j+1].name);
                swap(details[j].SGPA, details[j+1].SGPA);

            }
        }
    }
}

void insertionSort(result details[], int n){
        for(int i = 0; i< n; i++){
        string temp1 = details[i].name;
        int temp2 = details[i].roll;
        float temp3 = details[i].SGPA;

        int j = i-1;
        for(; j>=0; j--){
            if(details[j].name > temp1){
                //shift
                details[j+1].name = details[j].name;
                details[j+1].roll = details[j].roll;
                details[j+1].SGPA = details[j].SGPA;

            }else{
                break;
            }
        }
        details[j+ 1].name = temp1;
        details[j+ 1].roll = temp2;
        details[j+ 1].SGPA = temp3;
    }
}


void linearSearch(result *details, int n, float searchSGPA){
    for(int i = 0; i<n; i++){
        if(details[i].SGPA == searchSGPA){
            cout<<"Roll No. : "<<details[i].roll<<" Name : "<<details[i].name<<" SGPA : "<<details[i].SGPA<<endl;
        }
    }

}


int main(){
    int n;
    cout<<"Enter the number of students"<<endl;
    cin>>n;
    result info[n];
    cout<<"Enter info of students"<<endl;
    for(int i = 0; i<n; i++){
        // cout<<"Enter the roll number of student "<<i+1<<" : ";
        // cin>>info[i].roll;
        // cout<<"Enter name of the  student "<<i+1<<" : ";
        // cin>>info[i].name;
        // cout<<"Enter the SGPA of student number "<<i+1<<" : ";
        // cin>>info[i].SGPA;
        // cout<<endl;
        cin>>info[i].roll>>info[i].name>>info[i].SGPA;
    }
    cout<<"Details of all students is as follows : "<<endl;
    printDetails(info, n);

    cout<<endl;

// a. Arrange the list of Student in ascending order of roll number using bubble sort
    bubbleSort(info, n);
    cout<<"The list of students in ascending order of their roll number is : "<<endl;
    printDetails(info, n);
    cout<<endl;


//b. Arrange list of students alphabetically using insertion sort
    insertionSort(info, n);
    cout<<"The list of students in alphabetical order of their names : "<<endl;
    printDetails(info, n);
    cout<<endl;


//c.Arrange list of students to find out first ten toppers from a class. (Use Quick sort)

    quickSort(info, 0, n-1);
    cout<<"Details of Top 10 Students is as follows : "<<endl;
    printDetails(info, n);
    cout<<endl;


//d. binary searching for SGPA
    float searchSGPA;
    cout<<"Enter SGPA You want to search : ";
    cin>>searchSGPA;
    linearSearch(info, n, searchSGPA);
    cout<<endl;


//e. Searching For Name using Binary Search
    string temp;
    cout<<"Enter the name of student you have to search for : ";
    cin>>temp;
    //Sorting by name
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            if(info[i].name > info[j].name){
                swap(info[i].SGPA, info[j].SGPA);
                swap(info[i].name, info[j].name);
                swap(info[i].roll, info[j].roll);
            }
        }
    }
    binarySearchName(info, n, temp);
    cout<<endl;

    return 0;
}


/*
2 Raj 9.8
5 Sahil 9.8
3 Rohan 9.7
1 Pratik 8
4 Vivek 9
*/
assignment1a (2).cpp
Displaying assignment1a (2).cpp.
