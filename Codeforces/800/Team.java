/*
 * URL: https://codeforces.com/problemset/problem/231/A
 */
import java.io.*;

public class Team {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int ans=0;
        int n = Integer.parseInt(br.readLine().trim());
        for(int i=0;i<n;i++)
        {
            int zero = 0;
            String line = br.readLine().trim();
            String team[] = line.split(" ");
            for(int j=0;j<3;j++) if(Integer.parseInt(team[j])==0)zero++;
            if(zero<2)ans++;
            
        }
        
        out.println(ans);
        out.close();
    }

}
