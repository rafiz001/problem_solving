/*
 * https://codeforces.com/problemset/problem/106/B
 */
import java.io.*;

public class Choosing_Laptop {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine().trim());
        int cpu[]=new int[n],ram[]=new int[n],hdd[]=new int[n],price[]=new int[n];
        boolean outdated[] = new boolean[n];
        for(int i=0;i<n;i++)
        {
            String a[] = br.readLine().trim().split(" ");
            cpu[i] = Integer.parseInt(a[0]);
            ram[i] = Integer.parseInt(a[1]);
            hdd[i] = Integer.parseInt(a[2]);
            price[i] = Integer.parseInt(a[3]);
            outdated[i]=false;

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if( cpu[i]<cpu[j] && ram[i]<ram[j] && hdd[i]<hdd[j])
                {
                    outdated[i]=true;
                }
            }
        }

        int lowest=Integer.MAX_VALUE,ii=0;
        for(int i=0;i<n;i++)
        {
            if(outdated[i]==false && price[i]<lowest)
            {
                lowest=price[i];
                ii=i;
            }

            
        }
        out.println(ii+1);


        
        out.close();
    }

}
