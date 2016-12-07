#include <iostream>
using namespace std;
int main(){
	wchar_t s[] = {'上','海','自','来','水','来','自','海','上'};
	char *p = (char*)s;
	for(int i=0;i<9;i++,p++,p++)
	    printf("%c%c",*(p+1),*p);
	printf("\n"); //这样才显示原文
	for(int i=0;i<9;i++,p++,p++)
	    printf("%d ",s[i]);
	printf("\n"); //这样才显示原文
	cout<<sizeof(s)<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;

	char c1[] = "难难难";
	cout<<c1<<endl;
	cout<<sizeof(c1)<<endl;
	char c2[] = "难难";
	cout<<c2<<endl;
	cout<<sizeof(c2)<<endl;
	return 0;
}