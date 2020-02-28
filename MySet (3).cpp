#include <iostream>
#include <math.h>
using namespace std;
template <typename T>
class MySet
{
    T* arr;int size;
    public:
    MySet()
    {
        size=10;
        arr=new T[size];
    }
    MySet(int n)
    {
        size=n;
        arr=new T[size];
    }
    
    void input()
    {
        cout<<"\nEnter array elements\n";
        for(int i=0;i<size;i++)
            cin>>arr[i];
    }
    void display()
    {
        cout<<"\n{";
        for(int i=0;i<size;i++)
        {
            if(i==0)
                cout<<arr[i];
            else
                cout<<","<<arr[i];
        }
        cout<<"}\n";
       
    }
    void cardinality()
    {
        cout<<"\nCardinality of the given set is : "<<size<<endl;
    }
    void unique()
    {
        int i,j,k;
        for(i=0;i<size;++i)
        {
            for(j=i+1;j<size;)
            {
                if(arr[i]==arr[j])
                 {
                     for(k=j;k<size-1;k++)
                        arr[k]=arr[k+1];
                    --size;
                 }
                else
                ++j;
            }
        }
    }
       void powerset()
        {
            int powerset_size = pow(2, size);
            for(int counter = 0; counter < powerset_size; ++counter)
            {
                int count_elements = 0;
                cout << "{ ";
                for(int set = 0; set < size; ++set)
                    if(counter & (1 << set))
                    {
                        if(count_elements != 0)
                            cout << ", ";
                        cout << arr[set];
                        count_elements++;
                    }
                cout << " }";
                if(counter != powerset_size - 1)
                    cout << ", ";
            }
        }
    void operator = (const MySet &obj)
    {
        size=obj.size;
        for(int i=0;i<size;i++)
        arr[i]=obj.arr[i];
    }
    bool operator == (const MySet &obj)
    {
        if(size!=obj.size)
            return false;
        for(int i=0;i<size;i++)
            if(arr[i]!=obj.arr[i])
                return false;
        return true;
    }
    MySet operator + (MySet obj)
    {
        MySet un(size+obj.size);
        int j=0;
        for(int i=0;i<size;i++)
            un.arr[j++]=arr[i];
        for(int i=0;i<obj.size;i++)
            if(!hasElement(obj.arr[i]))
                un.arr[j++]=obj.arr[i];
        un.size=j;
        return un;
    }
    MySet operator * (MySet obj)
    {
        MySet in(size>obj.size?obj.size:size);
        int j=0;
        for(int i=0;i<size;i++)
            if(obj.hasElement(arr[i]))
                in.arr[j++]=arr[i];
        in.size=j;
        return in;
    }
    MySet operator - (MySet obj)
    {
        MySet diff(size);
        int j=0;
        for(int i=0;i<size;i++)
            if(!obj.hasElement(arr[i]))
                diff.arr[j++]=arr[i];
        diff.size=j;
        return diff;
    }
    MySet operator ^ (MySet obj2)
    {
        MySet diff1 = *this - obj2;
        MySet diff2 = obj2 - *this;
        MySet symdiff = diff1 + diff2;
        return symdiff;
    }
    bool hasElement(T element)
    {
        for(int i=0;i<size;i++)
            if(arr[i]==element)
                return true;
        return false;
    }
};
int main()
{   cout<<"\nENTER YOUR TYPE OF SET\n1.)INTEGER\n2.)CHARACTER\n3.)DOUBLE\n";
    int type;
    cin>>type;
    if(type==2){
    int size;
    cout<<"\nEnter the total number of elements in the set\n";
    cin>>size;
    MySet<char> ob1(size);
    ob1.input();
    cout<<"\nEnter the total number of elements in the set\n";
    cin>>size;
    MySet<char> ob2(size);
    ob2.input();
    cout<<"\n Set A after removing repeated elements , if any : \n";
    ob1.unique();
    ob1.display();
    cout<<"\n Set B after removing repeated elements , if any : \n";
    ob2.unique();
    ob2.display();
    MySet<char> ob3 = ob1 + ob2;
    cout<<"\n Union of the two sets is : \n";
    ob3.display();
    ob3 = ob1 * ob2;
    cout<<"\n Intersection of the two sets is : \n";
    ob3.display();
    ob3= ob1- ob2;
    cout<<"\n Difference A-B is : \n";
    ob3.display();ob3.cardinality();
    ob3 = ob2 - ob1;
    cout<<"\n Difference B-A is : \n";
    ob3.display();ob3.cardinality();
    ob3 = ob1 ^ ob2;
    cout<<"\n Symmetric difference of the two sets is : \n";
    ob3.display();ob3.cardinality();cout<<"POWERSET OF SET A "<<endl<<"{";ob1.powerset();
	cout<<"}"<<endl<<"POWERSET OF SET B "<<endl<<"{";ob2.powerset();cout<<"}"<<endl;
     if((ob1==ob2)==true)
        cout<<"\nTHE SETS ARE SAME ";
        else
        cout<<"\nTHE SETS ARE NOT SAME";
	}
	 if(type==1){
    int size;
    cout<<"\nEnter the total number of elements in the set\n";
    cin>>size;
    MySet<int> ob1(size);
    ob1.input();
    cout<<"\nEnter the total number of elements in the set\n";
    cin>>size;
    MySet<int> ob2(size);
    ob2.input();
  cout<<"\n Set A after removing repeated elements , if any : \n";
    ob1.unique();
    ob1.display();
    ob1.cardinality();cout<<"\n Set B after removing repeated elements , if any : \n";
    ob2.unique();
    ob2.display();ob2.cardinality();
    MySet<int> ob3 = ob1 + ob2;
    cout<<"\n Union of the two sets is : \n";
    ob3.display();
    ob3 = ob1 * ob2;
    cout<<"\n Intersection of the two sets is : \n";
    ob3.display();
    ob3= ob1 - ob2;
    cout<<"\n Difference A-B is : \n";
    ob3.display();ob3.cardinality();
    ob3 = ob2 - ob1;
    cout<<"\n Difference B-A is : \n";
    ob3.display();ob3.cardinality();
    ob3 = ob1 ^ ob2;
    cout<<"\n Symmetric difference of the two sets is : \n";
    ob3.display();ob3.cardinality();cout<<"POWERSET OF SET A "<<endl<<"{";ob1.powerset();
	cout<<"}"<<endl<<"POWERSET OF SET B "<<endl<<"{";ob2.powerset();
	cout<<"}"<<endl;
	 if((ob1==ob2)==true)
        cout<<"\nTHE SETS ARE SAME ";
        else
        cout<<"\nTHE SETS ARE NOT SAME";
	}
	if(type==3)
	{
    int size;
    cout<<"\nEnter the total number of elements in the set\n";
    cin>>size;
    MySet<double> ob1(size);
    ob1.input();
    cout<<"\nEnter the total number of elements in the set\n";
    cin>>size;
    MySet<double> ob2(size);
    ob2.input();
    cout<<"\n Set A after removing repeated elements : \n";
    ob1.unique();
    ob1.display();
    ob2.unique();cout<<"\n Set B after removing repeated elements , if any : \n";
    ob2.display();
    MySet<double> ob3 = ob1 + ob2;
    cout<<"\n Union of the two sets is : \n";
    ob3.display();
    ob3 = ob1 * ob2;
    cout<<"\n Intersection of the two sets is : \n";
    ob3.display();
    ob3= ob1 - ob2;
    cout<<"\n Difference A-B is : \n";
    ob3.display();ob3.cardinality();
    ob3 = ob2 - ob1;
    cout<<"\n Difference B-A is : \n";
    ob3.display();
    ob3.cardinality();
    ob3 = ob1 ^ ob2;
    cout<<"\n Symmetric difference of the two sets is : \n";
    ob3.display();
	ob3.cardinality();
	cout<<"POWERSET OF SET A "<<endl<<"{";ob1.powerset();
	cout<<"}"<<endl<<"POWERSET OF SET B "<<endl;ob2.powerset();
    cout<<"}"<<endl;
	 if((ob1==ob2)==true)
        cout<<"\nTHE SETS ARE SAME ";
        else
        cout<<"\nTHE SETS ARE NOT SAME";
	}
}
