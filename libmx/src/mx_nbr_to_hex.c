#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	if (nbr <= 0)
		return "0";
	char *str =  mx_strnew(100);;
    	int index = 0;

    	while (nbr != 0) {
         	int temp = nbr % 16;
         	
		if (temp < 10) {
             		str[index] = temp + 48;
             		index++;
         	}
         	else {
        	     str[index] = temp + 87;
            	     index++;
         	}
         	
		nbr /= 16;
    	}
    
	char *result = mx_strnew(index);

	for (int i = index; i >= 0; i--) 
		result[index - i - 1] = str[i];
    	
	return result;
}
