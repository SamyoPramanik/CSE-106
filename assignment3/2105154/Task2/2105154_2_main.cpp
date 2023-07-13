#include"2105154_2_stack.cpp"
int main()
{
    stack< char> st;// data type change
    int q;
    char p;//data type change
    while(1)
    {
        cin>>q;
        if(q==0){return 1;}
        if(q==1)
        {
            st.clear();
            st.show();
        }
       else if(q==2)
        {
            cin>>p;
            st.push(p);
            st.show();
        }
       else if(q==3)
       {
        char item=st.pop();//data type change
        st.show();
        cout<<item<<endl;
       }
       else if(q==4)
       {
        st.show();
        cout<<st.length()<<endl;
       }
     else if(q==5)
     {
        st.show();
        cout<<st.topvalue()<<endl;
     }
     else if(q==6)
     {
        st.show();
            if(st.isempty()){
                    cout<<"1"<<endl;
            }    
            else{
                cout<<"0"<<endl;
            }    
     }

    }
}