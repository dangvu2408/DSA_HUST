/*Create a singly linked list to manage computer lines (models) in a store.
Information about each model includes: - mComputer (model code - long type),
									   - bQuantity (purchased quantity - int type),
									   - sQuantity (sold quantity - int type),
									   - bPrice (purchase unit price - float type),
									   - sPrice (unit selling price - float type),
									   - profit (profit - double type).
Perform the following requests in C/C++ language:
	1. Declare data structures
	2. The function initializes an empty list to store computer models
	3. The function adds a model to the beginning of the list
	4. Function to delete a model with a given model number
	5. Function to calculate profit of all models (calculate profit)
	6. The function retrieves the profit of a model whose model number is equal to your student number
	7. The function displays information about the models with the highest profit
	8. The function creates a new list from the above list but arranged in descending order of profit.
*/

#include <bits/stdc++.h>
using namespace std;
long mssv = 20223830;
vector<double> pro;
class model { 
	public:
		long mCom;
		int bQuan, sQuan;
		float bPri, sPri;
		double profit;
		model *next;
		model() {
			next = NULL;
		} // contructor
		model(long mCom, int bQuan, int sQuan, float bPri, float sPri, double profit) {
			this -> mCom = mCom;
			this -> bQuan = bQuan;
			this -> sQuan = sQuan;
			this -> bPri = bPri;
			this -> sPri = sPri;
			this -> profit = profit;
			next = NULL;
		} //contructor with parameters
}; //Declare data structure

class modelList {
	public:
		model *head, *tail;
		modelList() {
			head = NULL;
			tail = NULL;
		} //contructor, initializes an empty list to store computer models
		
		void addToHead(long mCom, int bQuan, int sQuan, float bPri, float sPri, double profit) {
			model *newModel = new model(mCom, bQuan, sQuan, bPri, sPri, profit);
			newModel -> next = head;
			head = newModel;
			if (tail == NULL) tail = head;
		} //add a new model to the head of list
		
		void addToTail(long mCom, int bQuan, int sQuan, float bPri, float sPri, double profit) {
			model *newModel = new model(mCom, bQuan, sQuan, bPri, sPri, profit);
			if (tail == NULL) tail = head = newModel;
			else {
				tail -> next = newModel;
				tail = newModel;
			}
		} //add a new model to the end of list
		  //use addToTail(...) cause the displayed data will be
		  //in the correct order when entered
		  
		double profitCal(int bQuan, int sQuan, float sPri, float bPri) {
			return (double)(sQuan * sPri - bQuan * bPri);
		} //function: calculate the profit
		
		model *deleteModel(long key) {
	        model *res = NULL;
	        if (head != NULL)
	            if (head -> mCom == key) {
	                res = head;
	                if (head == tail) tail = head = NULL;
	                else head = head -> next;
	            } else {
	                model *tmp = head;
	                while (tmp -> next != NULL) {
	                    if (tmp -> next -> mCom == key) {
	                        res = tmp -> next;
	                        tmp -> next = tmp -> next -> next;
	                        break;
	                    }
	                    tmp = tmp -> next;
	                }
	            }
	        return res;
    	} //detete a model in the list with the given model num
    	
    	model *findModelId(long key) {
	        model *res = NULL;
	        model *tmp = head;
	        while (tmp != NULL) {
	            if (tmp -> mCom == key) {
	                res = tmp;
	                break;
	            }
	            tmp = tmp -> next;
	        }
	        return res;
    	} //method: find a model by id with a key...
    	
    	void findToProfit(modelList com) {
    		model *find = com.findModelId(mssv); //key is student ID
    		if (find) cout << "Model profit: " << find -> profit << endl;
    		else cout << "Model not found!!" << endl;
		} //method: retrieves the profit of a model whose model number is equal to your student number
		
		void display() {
			model *tmp = head;
			int i = 1;
			while (tmp != NULL) {
				cout << "COMPUTER MODEL " << i << ": " << endl;
				cout << "Computer model: " << tmp -> mCom << endl;
				cout << "Quantity purchase: " << tmp -> bQuan << endl;
				cout << "Quantity issued: " << tmp -> sQuan << endl;
				cout << "Price purchase: " << tmp -> bPri << endl;
				cout << "Price issued: " << tmp -> sPri << endl;
				// tmp -> profit = tmp -> sPri - tmp -> bPri; //codeline: calculate the profit
				tmp -> profit = profitCal(tmp -> bQuan, tmp -> sQuan, tmp -> sPri, tmp -> bPri);
				cout << "Profit: " << tmp -> profit << endl << endl;
				tmp = tmp -> next; i++;
			}
		} //print the data to the screen
		
		model *findModelProfit(double key) {
	        model *res = NULL;
	        model *tmp = head;
	        while (tmp != NULL) {
	            if (tmp -> profit == key) {
	                res = tmp;
	                break;
	            }
	            tmp = tmp -> next;
	        }
	        return res;
    	} //method: find a model by profit with a key...
    	
		void displayMaxProfit(modelList com) {
			model *tmp = head;
			while (tmp != NULL) {
				pro.push_back(tmp -> profit);
				tmp = tmp -> next;
			}
			sort(pro.begin(), pro.end());
			reverse(pro.begin(), pro.end());
			
			model *find = com.findModelProfit(pro[0]); //key is the first element of pro vector
    		if (find != NULL) {
    			cout << "\n----------COMPUTER MODEL (FIND BY PROFIT)----------" << endl;
    			cout << "Computer model: " << find -> mCom << endl;
				cout << "Quantity purchase: " << find -> bQuan << endl;
				cout << "Quantity issued: " << find -> sQuan << endl;
				cout << "Price purchase: " << find -> bPri << endl;
				cout << "Price issued: " << find -> sPri << endl;
				cout << "Profit: " << find -> profit << endl << endl;
			} 
    		else cout << "Model not found!!" << endl;
    		find = NULL;
		} //print the data of the highest profit to the screen
		
		modelList reverseModel(modelList com1, modelList com2) {
			model *found = NULL;
			for (int i = 0; i < pro.size(); i++) {
				found = com1.findModelProfit(pro[i]);
				if(found != NULL) com2.addToTail(found -> mCom, found -> bQuan, found -> sQuan, found -> bPri, found -> sPri, found -> profit);
				else cout << "Cannot find the model..." << endl;
				found = NULL;
			}
			return com2;
		}
};

int main(){
	modelList mCom1, mCom2;
	
	mCom1.addToTail(20220001, 120, 116, 125.5, 127.0, 0);
	mCom1.addToTail(20220002, 140, 130, 110.4, 120.1, 0);
	mCom1.addToTail(20220003, 115, 110, 130.1, 150.9, 0);
	mCom1.addToTail(20221335, 150, 143, 150.1, 155.4, 0);
	mCom1.addToTail(20226353, 210, 190, 210.6, 235.0, 0);
	mCom1.addToTail(20223830, 400, 375, 92.1, 98.9, 0);
	mCom1.addToTail(20224200, 115, 110, 130.1, 150.9, 0);
	mCom1.addToTail(20223797, 1054, 997, 45.12, 50.3, 0);
	mCom1.addToTail(20224316, 65, 45, 1270.1, 1300.9, 0);
	mCom1.addToTail(20227453, 900, 899, 130.0, 140.0, 0);
	mCom1.addToTail(20222385, 95, 86, 200.1, 209.9, 0);
	mCom1.addToTail(20221904, 1204, 1156, 67.4, 70.9, 0);
	mCom1.display();
	
	cout << "\n----------DELETE MODEL PROTOTYPE----------" << endl;
/*	model *delModel = mCom1.deleteModel(20224200);
	if (delModel != NULL) cout << "Model Deleted..." << endl << endl;
    else cout << "Model not found!!!" << endl << endl;
    mCom1.display();   */
    
    mCom1.findToProfit(mCom1);
    mCom1.displayMaxProfit(mCom1);
    cout << endl << endl;
    mCom2 = mCom1.reverseModel(mCom1, mCom2);
    mCom2.display();
	return 0;
}
