#include<stdio.h>
#include<stdlib.h>
//ɱ�����ֱ�Ϊ4�����ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
int main()
{
	char killer=0;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if ((killer != 'A') + (killer == 'C') +( killer == 'D') +( killer != 'D') == 3)
			printf("%c", killer);
	}
	printf("\n");
    system("pause");
	return 0;

}