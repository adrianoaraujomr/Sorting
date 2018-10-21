typedef struct eInteger{
	int data;
	char key[5];
} EInteger;

typedef struct eString{
	char data[400];
	char key[5];
} EString;

typedef struct eBitDna{
	char data[400];
	char key[5];
	int size;
} EBitDna;

typedef struct eDouble{
	long dec;
	char flt[25];
	char key[5];
} EDouble;

void IntMerge(EInteger *v,int f,int m,int l);
void IntMergeSQ(EInteger *v,int f,int l);
void IntMergeSort(EInteger *v,int f,int l);

void StrMerge(EString *v,int f,int m,int l);
void StrMergeSQ(EString *v,int f,int l);
void StrMergeSort(EString *v,int f,int l);

void BnaMerge(EBitDna *v,int f,int m,int l);
void BnaMergeSQ(EBitDna *v,int f,int l);
void BnaMergeSort(EBitDna *v,int f,int l);

void DblMerge(EDouble *v,int f,int m,int l);
void DblMergeSQ(EDouble *v,int f,int l);
void DblMergeSort(EDouble *v,int f,int l);

