class student
{
  protected:
      char name[20];
      int usn=0;
  public:
      void getdetail(void)
      {
    cout<<"\n\nEnter name :- ";
    cin>>name;
    cout<<"\nEnter usn    :- ";
    cin>>usn;
      }
      void dispdetail(void)
      {
    cout<<"\n\nNAME      :- "<<name;
    cout<<"\nUSN         :- "<<usn;
      }
};