/*
 * In the name of ALLAH, the Most Gracious, the Most Merciful
 * URL: https://codeforces.com/problemset/problem/2035/B
 */
import java.io.*;

public class Everyone_Loves_Tres {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine().trim());
        for(int i=0;i<t;i++)
        {
            int n = Integer.parseInt(br.readLine().trim());
            String res = "";
            if(n==1 || n==3) res="-1";
            else if((n&1) == 1) //even
            {
                for(int j=0;j<n-4;j++)
                {
                    res+="3";
                }
                res+="6366";
            }
            else //odd
            {
                for(int j=0;j<n-2;j++)
                {
                    res+="3";
                }
                res+="66";
            }
            
            out.println(res);
            
           
            
        }
        

        out.close();
    }
}
