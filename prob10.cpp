#include <iostream>
#include <vector>
using namespace std;

int main()
{
    char choice{};
    
    
    vector<int>list {};
    do{	cout << "these are valid choices \nP-print the list \nA-add a number \nM-display mean of all numbers \nS-display smallest number \nL-display largest number \nQ-quit " << endl;
        cout << "\n\n\nEnter yur choice:" << endl;
        cin >> choice;
        
        if (choice=='p' || choice=='P'){
           if (list.size()==0){
               cout << "[] list is empty\n\n\\n" << endl;
			   }
           else {
               cout <<"[";
               for(auto num: list)
                   cout << num << " ";
               cout << "]\n\n\n"<< endl;}    }
            
        
        else if (choice=='a'||choice=='A'){
            int num2{};
            cout << "enter the number you want to add" << endl;
            cin >> num2;
            list.push_back(num2);
            cout << num2 << " added\n\n\n";
            }
        
		else if (choice=='m'|| choice=='M'){
			if(list.size()==0){
                cout << "this is not possible\n\n\n" ;
            } 
            else{
                
			    int sum{};
			    double mean{};
                for(auto num : list){
                    sum +=num;
                }
                cout << "mean of sums in list is " << static_cast<double>(sum)/list.size()<<"\n\n\n";
            }
		}
        
        else if (choice=='s' ||choice== 'S'){
            if(list.size()==0){
                cout << "this is not possible\n\n\n" ;
            } 
            else{
                int smallest = list.at(0);
                for (auto num: list)
                    if (num < smallest)
                        smallest = num;
                cout << "smallest number is "<< smallest << "\n\n\n";
               }
        }
        else if (choice=='l' || choice == 'L'){
            if(list.size()==0){
                cout << "this is not possible\n\n\n" ;
            } 
            else {
                int largest = list.at(0);
                for (auto num : list)
                    if (num > largest)
                        largest = num;
                cout << "largest number is " << largest << "\n\n\n";        
                
            }
        }
     }
    while (choice!='q' && choice!='Q');
        
        cout << "thanks goodbye" << endl;
        return 0;
    
}

