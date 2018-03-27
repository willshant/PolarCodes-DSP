#include "polarDecode.h"

char crc[crcLen+1] = {1,1,0,0,0,0,1,1,0,0,1,0,0,1,1,0,0,1,1,1,1,1,0,1,1};
char position[codeLen] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

int crcCheck(char *a){
	int i, j, sum = 0;
	char b[infoLen];
	memcpy(b, a, sizeof(char) * infoLen);
	for(i=0;i<randLen;i++){
		if(b[i] == 1)
			for(j=0;j<crcLen+1;j++)
				b[i+j] ^= crc[j];
	}
	for(i=0;i<randLen;i++)
		sum += b[i];
	return sum;
}

char sign(double x){
	char z;
	if (x>0)
		z=1;
	else if (x<0)
		z=-1;
	else
		z=0;
	return(z);
}

double min_double(double a,double b){
	if (a>=b)
		return b;
	else
		return a;
}

double likelihood_rate(int n,int i,char *uu,double *LLR_matrix){
	int j,k=0;
	double LLR=0,L1=0,L2=0;
    char ue[infoLen],uoe[infoLen];
	if (n!=1){
		/* odd number */
		if (i&1==1){
			for(j=0;j<i-1;j=j+2,k++){
//				uo[k]=uu[j];
				ue[k]=uu[j+1];
				uoe[k]=(uu[j]+ue[k])&1;
			}
			L1=likelihood_rate(n/2,(i+1)/2,uoe,LLR_matrix);
			L2=likelihood_rate(n/2,(i+1)/2,ue,LLR_matrix+n/2);
			LLR=sign(L1*L2)*min_double(fabs(L1),fabs(L2));
		}
		/* even number */
		else{
			for(j=0;j<i-2;j=j+2,k++){
//				uo[k]=uu[j];
				ue[k]=uu[j+1];
				uoe[k]=(uu[j]+ue[k])&1;
			}
			L1=likelihood_rate(n/2,i/2,uoe,LLR_matrix);
			L2=likelihood_rate(n/2,i/2,ue,LLR_matrix+n/2);
			LLR=(1-2*uu[i-2])*L1+L2;
		}
        return LLR;
	}
    else{
		LLR=LLR_matrix[0];
		return LLR;
	}
}

double path_metric(int i, char u, double pm_former, double llr){
	double pm_new;
	if ((position[i]==1 || (position[i]==0 && u==0)) && ((1-2*u) == sign(llr))){
		if (i==0)
			pm_new = 0;
		else 
			pm_new = pm_former;
	}
	else if ((position[i]==1 || (position[i]==0 && u==0)) && ((1-2*u) != sign(llr))){
		if (i==0)
			pm_new = 0-fabs(llr);
		else
			pm_new = pm_former-fabs(llr);
	}
	else
		pm_new = LLONG_MIN;
	return pm_new;
}


typedef struct
{
	/* value */
	double cj;
	/* index */
	char px;
}PAIR;

void Swap(PAIR *A, int i, int j){
    double cj_tmp;
    char px_tmp;
    cj_tmp = A[i].cj;
    A[i].cj = A[j].cj;
    A[j].cj = cj_tmp;
    px_tmp = A[i].px;
    A[i].px = A[j].px;
    A[j].px = px_tmp;
}

void QuickSort(PAIR *A, int L, int R){
    if(L < R){
        int pivot = A[L].cj;
        int i = L+1, j = R;
        while(i <= j){
            while(i <= j && A[i].cj >= pivot){
                i++;
            }
            while(i <= j && A[j].cj < pivot){
                j--;
            }
            if(i <= j){
                Swap(A, i, j);
                i++;
                j--;
            }
        }
        Swap(A, L, j);
        QuickSort(A, L, j-1);
        QuickSort(A, j+1, R);
    }
}

void polarDec(double *llr_matrix, char *dec){
    int i, j, k;
    int flagflag;                       // count for flag
    char
        reverse_all[List * flag],
        u,                              // the currently guessing bit
        u_matrix[List * codeLen],       // candidate sequences 32*1024
        uu[codeLen],                    // decoded i bits
        temp[List * codeLen];           // 32*1024
    double llr;
    double u_matrix_pm[List];           // pm of candidate sequences
    PAIR pm_temp[2*List];
    /*
        initialising
        */
//    flag = log((double)List)/log((double)2);
    flagflag = 0;

    memset(u_matrix, 0, List * codeLen);
    memset(reverse_all, 0, List * flag);

    for(i=1;i<List;i++){
        memcpy(reverse_all+i*flag, reverse_all+(i-1)*flag, flag);
        for(j=flag-1;j>=0;j--){
            if(reverse_all[i*flag+j] == 0){
                reverse_all[i*flag+j] = 1;
                for(k=j+1;k<flag;k++)
                    reverse_all[i*flag+k] = 0;
                break;
            }
        }
    }

    /*
        decoding
        */
    for(i=0;i<codeLen;i++){

        if(position[i] == 0){
            if(i == 0){
                u = 0;
                llr = likelihood_rate(codeLen, i+1, uu, llr_matrix);
                for(j=0;j<List;j++)
                    u_matrix_pm[j] = path_metric(i, u, 0, llr);
            }
            else{
                u = 0;
                for(j=0;j<List;j++){
                    memcpy(uu, u_matrix+j*codeLen, i);
                    llr = likelihood_rate(codeLen, i+1, uu, llr_matrix);
                    u_matrix_pm[j] = path_metric(i, u, u_matrix_pm[j], llr);
                }
            }
        }
        else{
            flagflag += 1;
            if(flagflag <= flag){
                for(k=0;k<List;k++)
                    u_matrix[i+k*codeLen] = reverse_all[flagflag-1+k*flag];
                for(j=0;j<List;j++){
                    u = u_matrix[i+j*codeLen];
                    memcpy(uu, u_matrix+j*codeLen, i);
                    llr = likelihood_rate(codeLen, i+1, uu, llr_matrix);
                    u_matrix_pm[j] = path_metric(i, u, u_matrix_pm[j], llr);
                }
            }
            else{
                for(j=0;j<List;j++){
                    memcpy(uu, u_matrix+j*codeLen, i);
                    llr = likelihood_rate(codeLen, i+1, uu, llr_matrix);
                    pm_temp[2*j].cj = path_metric(i, 1, u_matrix_pm[j], llr);
                    pm_temp[2*j+1].cj = path_metric(i, 0, u_matrix_pm[j], llr);
                    pm_temp[2*j].px = 2*j;
                    pm_temp[2*j+1].px = 2*j+1;
                }
                QuickSort(pm_temp, 0, 2 * List - 1);
                memset(temp, 0, codeLen);
                for(j=0;j<List;j++){
                    if(pm_temp[j].px % 2 == 0){
                        memcpy(temp+j*codeLen, u_matrix+pm_temp[j].px/2*codeLen, i);    temp[i+j*codeLen] = 1;}
                    else{
                        memcpy(temp+j*codeLen, u_matrix+(pm_temp[j].px-1)/2*codeLen, i);    temp[i+j*codeLen] = 0;}
                }
                for(j=0;j<List;j++){
                    memcpy(u_matrix+j*codeLen, temp+j*codeLen, i+1);
                    u_matrix_pm[j] = pm_temp[j].cj;
                }
            }
        }

    }

    /*
        get infobits
        */
    k = 0;
    for(i=0;i<codeLen;i++){
        if(position[i]){
            for(j=0;j<List;j++)
                u_matrix[k+j*codeLen] = u_matrix[i+j*codeLen];
            k++;
        }
    }

    /*
        remove crc bits
        */
    k = 0;
    for(i=0;i<List;i++){
        if(crcCheck(u_matrix+i*codeLen) == 0)
            k = i;  break;
    }
    memcpy(dec, u_matrix+k*codeLen, sizeof(char) * randLen);
}
