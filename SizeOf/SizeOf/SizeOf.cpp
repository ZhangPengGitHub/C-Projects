#include <iostream>
using namespace std;
int main(){
	wchar_t s[] = {'上','海','自','来','水','来','自','海','上'};
	char *p = (char*)s;
	for(int i=0;i<9;i++,p++,p++)
	    printf("%c%c",*(p+1),*p);
	printf("\n");//这样才显示原文
	for(int i=0;i<9;i++,p++,p++)
	    printf("%d ",s[i]);
	printf("\n");
	cout<<sizeof(s)<<endl;
    //system("PAUSE");
    //return EXIT_SUCCESS;

	/*
	char c1[] = "难难难";
	cin>>c1;
	cout<<c1<<endl;
	cout<<sizeof(c1)<<endl;
	char c2[5];
	cin>>c2;
	cout<<c2<<endl;
	cout<<sizeof(c2)<<endl;
	*/
	char c3[10]={'1','2','3','4','5','6','7','8','9'}; 
	gets(c3);
	cout<<c3<<endl;
	cout<<sizeof(c3)<<endl;

	int i = '我';
	char c[] = "我";
	cout << i << endl;
	cout << c << endl;
	cout << sizeof(c) << endl;

	char c0;
	cin >> c0;
	cout << c0 << endl;

	return 0;
}