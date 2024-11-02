/*
 * URL: https://codeforces.com/problemset/problem/282/A
 */
import java.io.*;

public class Bit_pp {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int ans=0;
        int n = Integer.parseInt(br.readLine().trim());
        for(int i=0;i<n;i++)
        {
            String keyword = br.readLine().trim();
            if(keyword.equals("++X") || keyword.equals("X++")) ans++;
            else if(keyword.equals("--X") || keyword.equals("X--"))ans--;
            
        }
        
        out.println(ans);
        out.close();
    }

}
