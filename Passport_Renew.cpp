/*A ist is maintained in the database to store the renewed passports arranged in the increased order of passport ID. 
The list already would contain there records renewed till the previous day. Later the office personnel wish to sort the 
records based on the date of renewal so as to know the count of renewals done each day.*/
#include<iostream>
#include<string>
using namespace std;
//Hearder Files used

//structure date having year,month and day
typedef struct Date
{
    int yr,mnth,dy;
    
}dt;

//structure of List contains passport id and date  
typedef struct RenewPassport
{
    int P_id;
    struct Date P_date;
}rp;

//function to compare the day,month and year seperately 
bool datecom(const dt dd1,const dt dd2){
    if (dd1.yr < dd2.yr)
    {
      return 1;
    }
    if (dd1.yr == dd2.yr && dd1.mnth < dd2.mnth)
    {
    return 1;
    }
    if (dd1.yr == dd2.yr && dd1.mnth == dd2.mnth && dd1.dy < dd2.dy){
        return 1;
    }
        return 0;
}

//Main function
int main()
{
	int num,min;
	rp arr[100];
	rp c_arr[100];
	dt ar[15];
	dt c_ar[15];
	rp temp;
	//variables declared
	
	//Insertion of Records
	cout<<"Enter number of Records to be Renew: ";
	cin>>num;
	
	cout<<"Fill the Information!!\n";
	for(int i=0;i<num;i++)
    {
        cout<<i+1<<" Passport ID : ";
        cin>>arr[i].P_id;
        cout<<i+1<<" Renewal Day: ";
        cin>>ar[i].dy;
        cout<<i+1<<" Renewal Month: ";
        cin>>ar[i].mnth;
        cout<<i+1<<" Renewal Year: ";
        cin>>ar[i].yr;
    }
    
    //Coping the Records for future use
    for(int i=0;i<num;i++)
    {
        c_arr[i]=arr[i];
    }
     for(int i=0;i<num;i++)
    {
        c_ar[i]=ar[i];
    }

    //Sorting data according to their passport Id
    //Here, i use insertion sort
	for (int i=1;i<num;i++)
	{
		temp=arr[i];
		int j=i-1;
		while(j>=0 && (temp.P_id < arr[j].P_id))
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;

	}

    //Printing the Sorted List 
    cout<<"\nlist of Records!!\n";
	for (int i=0;i<num;i++)
	{
	    cout<<i+1<<" Passport ID : "<<arr[i].P_id<<"\n";
		cout<<i+1<<" Renewal Date : ";
		cout<<ar[i].dy<<"/"<<ar[i].mnth<<"/"<<ar[i].yr<<"\n";
	}


    //Sorting data according to the Renewed date
    //Here, i use selection sort using min value
	for (int i=0;i<num;i++)
	{
		min=i;
		for(int j=i+1;j<num;j++)
		{
			if(datecom(c_arr[j].P_date,c_arr[min].P_date)==true)
			{
				min=j;
			}
		}
		temp=c_arr[i];
		c_arr[i]=c_arr[min];
		c_arr[min]=temp;
	}
	
	//Printing the Sorted List 
    cout<<"\nlist of Renewed Records!!\n";
	for (int i=0;i<num;i++)
	{
	   cout<<i+1<<" Passport ID : "<<c_arr[i].P_id<<"\n";
	   cout<<i+1<<" Renewal Date : ";
	   cout<<c_ar[i].dy<<"/"<<c_ar[i].mnth<<"/"<<c_ar[i].yr<<"\n";

	}


}
