/*
 * URL: https://codeforces.com/problemset/problem/71/A
 */
import java.io.*;

public class Way_Too_Long_Words {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine().trim());
        for(int i=0;i<n;i++)
        {
            String word = br.readLine().trim();
            if(word.length()>10)
            {
                out.println(""+word.charAt(0)+(word.length()-2)+word.charAt(word.length()-1));
            }
            else
            {
                out.println(word);
            }
        }
        
        
        out.close();
    }

}
