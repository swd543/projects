import java.util.Scanner;

public class boola

{

     public static void main(String []args)

     {

        int output=0,c=0;long input=0;

        Scanner in = new Scanner(System.in);


        System.out.print("\nEnter binary number :");

        try{
		input=in.nextLong();
	}catch(Exception e)
	{
		System.out.println("You son of a pussy what is this? "+e);
		return;
	};
	
	do{
		if(input%10==0||input%10==1)
		{		
			output+=(int)(Math.pow(2,c++))*(int)(input%10);
			input/=10;
		}
		else
		{
			System.out.println("You motherfucking cunt enter a binary number");
			return;
		}
	}while(input>0);

	System.out.println("Decimal equivalent is : "+output);
	
      }
}
