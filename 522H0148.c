#include <stdio.h>
#include <math.h>
#include <string.h>
#define pi 3.1415926535

int X[5][6]={	
				{5,7,10,12,15,20},
				{20,5,7,10,12,15},
				{15,20,5,7,10,12},
				{12,15,20,5,7,10},
				{10,12,15,20,5,7},
				
			};

int sumuoc(int);
struct Function {
	float nd;
	int bc;
	int bg;
} A;


int Wind(int n,int dc,int dg,int lg)
{	
    A.bc=floor(n/(dc*dc));
    if(A.bc>lg)
    {
        A.bc=lg;
        A.nd=n-lg*(dc*dc);
        A.bg=0;
        return 1;
    }
    else
    {
        A.bc=floor(n/(dc*dc));
        A.nd=fmod(n,dc*dc);
        A.bg=floor(A.nd/((pi*dg*dg)/4));
        A.nd=fmod(A.nd,pi*dg*dg/4);
        return 1;
    }
}






int Fog(int n,int dc,int dg,int lg)
{
	return 1;
}






int Cloud(int n,int dc,int dg,int lg)
{
	if (sumuoc(n)==sumuoc(lg))
	{
		return 1;
	}
	else
	{
		    A.bg=floor(n/(pi*dg*dg*(0.25)));
    		if(A.bg>lg)
   			{		
       			A.bg=lg;
        		A.nd=n-lg*floor(pi*dg*dg*(0.25));
        		A.bc=0;
        		return 1;
   			}
   			else
    		{
     		  	A.bg=floor(n/(pi*dg*dg*(0.25)));
     		  	A.nd=fmod(n,pi*dg*dg*(0.25));
     		   	A.bc=floor(A.nd/(dc*dc));
        		A.nd=fmod(A.nd,dc*dc);
        		return 1;
        	}
	}
}




int Rain(int n,int dc,int dg,int lg)
{
	int k;
	k=floor(n/(dc*dc+dg*dg*pi*(0.25)));
	if((2*k)<=lg)
	{
		A.bc=k;
		A.bg=k;
		A.nd=n-k*(dc*dc)-k*(dg*dg*(0.25)*pi);
		return 1;
	}
	if((2*k)>lg)
	{
		if(lg%2==0)
		{
			A.bc=lg/2;
			A.bg=lg/2;
			A.nd=n-A.bc*dc*dc-A.bg*dg*dg*pi*(0.25);
			return 1;
		}
		else
		{
			if( (n-floor(lg/2)*dc*dc-(floor(lg/2)+1)*dg*dg*pi*(0.25)) > (n-floor(lg/2)*dg*dg*(0.25)*pi - (floor(lg/2)+1)*dc*dc ) )
			{
				A.bg=floor(lg/2);
				A.bc=floor(lg/2)+1;
				A.nd=n-floor(lg/2)*dg*dg*(0.25)*pi - (floor(lg/2)+1)*dc*dc;
				return 1;
			}
			else
			{
				A.bc=floor(lg/2);
				A.bg=floor(lg/2)+1;
				A.nd=n-floor(lg/2)*dc*dc-(floor(lg/2)+1)*dg*dg*pi*(0.25);
				return 1;
			}
		}
	}
}


int Sun(int n,int dc,int dg,int lg)
{
	int G;
	G=dc%6;
	int H;
	H=lg%5;
	n= n+ (int)(X[H][G]*(0.01)*n);
	lg=lg-X[H][G];
	if(((int)dc+(int)dg)%3==0)
	{
		return Rain(n,dc,dg,lg);
	}
	else
	{
		if (((int)dc+(int)dg)%3==1)
		{
			return Wind(n,dc,dg,lg);
		}
		else
		{	
		 	if(((int)dc+(int)dg)%3==2)
			{
				return Cloud(n,dc,dg,lg);
			}
		}
	
	}
}




int sumuoc(int k)
{
	long S = 0;
	int i;
	for(i = 1; i <= k; i++)
	{
		if(k % i == 0)
   		{
      		S = S + i;
		}
 	}
	return S;
}





int main()
{
    float n,dc,dg,lg;
    int dkn=1,dklg=1,dkw,dkdc=1,dkdg=1,i;
    char w[100];
    FILE *input, *output;
    input =fopen("input.inp","r");
    fscanf(input,"%f %f %f %f %s",&n,&dc,&dg,&lg,w);
    fclose(input);
    if(n!=(int)n || n<0 || n>1000)
        dkn=0;
    else
        dkn=1;
    
    if(dc!=(int)dc || dc==0)
    {
        dkdc=0;
    }
    else
    {
		if(dc<0)
		{
			dc=0;
			dkdc=1;
		}
		else
		{
           dkdc=1;
        }
   }
    
    if(dg!=(int)dg || dg==0)
    {
       dkdg=0;
    }
    else
    {
       if(dg<0)
       {
       		dg=0;
       		dkdg=1;
       }
       else
       {
     		dkdg=1;
    	}
    }
    

    if(lg!=(int)lg || lg<1 || lg>300)
        dklg=0;
    else
     	lg=(int)lg;
        dklg=1;
    if(strcmp(w,"Rain")==0)
    {
        dkw=1;
    }
    else
    {
        if(strcmp(w,"Sun")==0)
        {
            dkw=2;
        }
        else
            if(strcmp(w,"Cloud")==0)
            {
            dkw=3;
            }
            else
                if(strcmp(w,"Fog")==0)
                {
                    dkw=4;
                }
                else
                    if(strcmp(w,"Wind")==0)
                    {
                        dkw=5;
                    }
                    else
                        dkw=0;
	}


    if(dkn==0|| dkdc==0|| dkdg==0|| dklg==0 || dkw==0)
    {
    	output=fopen("output.out","w");
        fprintf(output,"-1 -1 %.3f",n);
        fclose(output);
    }
    else
    {
    	switch (dkw)
    	{
    	case 1:
        		Rain(n,dc,dg,lg);
        		output=fopen("output.out","w");
        		fprintf(output,"%d %d %.3f",A.bc,A.bg,A.nd);
        		fclose(output);
        		break;
  		case 2:
  				Sun(n,dc,dg,lg);
  				if(((int)dc+(int)dg)%3==0)
				{
					output=fopen("output.out","w");
					fprintf(output,"%d %d %.3f",A.bc,A.bg,A.nd);
					fclose(output);
				}
				else
				{
					if (((int)dc+(int)dg)%3==1)
					{
						output=fopen("output.out","w");
						fprintf(output,"%d %d %.3f",A.bc,A.bg,A.nd);
						fclose(output);
					}
					else
					{	
					 	if(((int)dc+(int)dg)%3==2)
						{
							output=fopen("output.out","w");
							fprintf(output,"%d %d %.3f",A.bc,A.bg,A.nd);
							fclose(output);
						}
					}
				}
  				break;
  		case 3:
  				Cloud(n,dc,dg,lg);
   				if (sumuoc(n)==sumuoc(lg))
				{
					output=fopen("output.out","w");
					fprintf(output,"%.0f",n);
					fclose(output);
				}
				else
				{
					output=fopen("output.out","w");
        			fprintf(output,"%d %d %.3f",A.bc,A.bg,A.nd);
        			fclose(output);
        		}
  				break;
  		case  4:
  				Fog(n,dc,dg,lg);
  				output=fopen("output.out","w");
  				fprintf(output,"%.0f %.0f %.3f",dc,dg,n);
  				fclose(output);
  				break;
  		case 5 :
  				Wind(n,dc,dg,lg);
  				output=fopen("output.out","w");
  				fprintf(output,"%d %d %.3f",A.bc,A.bg,A.nd);
  				fclose(output);
  				break;	
		}
	}
		return 0;
}
