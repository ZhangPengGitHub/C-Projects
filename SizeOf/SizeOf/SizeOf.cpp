#include <iostream>
using namespace std;
int main(){
	wchar_t s[] = {'��','��','��','��','ˮ','��','��','��','��'};
	char *p = (char*)s;
	for(int i=0;i<9;i++,p++,p++)
	    printf("%c%c",*(p+1),*p);
	printf("\n"); //��������ʾԭ��
	for(int i=0;i<9;i++,p++,p++)
	    printf("%d ",s[i]);
	printf("\n"); //��������ʾԭ��
	cout<<sizeof(s)<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;

	char c1[] = "������";
	cout<<c1<<endl;
	cout<<sizeof(c1)<<endl;
	char c2[] = "����";
	cout<<c2<<endl;
	cout<<sizeof(c2)<<endl;
	return 0;
}