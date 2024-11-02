/*
 * URL: https://codeforces.com/problemset/problem/456/A
 */
import java.io.*;

public class Laptops {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        boolean laptop1=false;
        boolean laptop2=false;
        int n = Integer.parseInt(br.readLine().trim());
        for(int i=0;i<n;i++)
        {
            String line[] = br.readLine().trim().split(" ");
            if(Integer.parseInt(line[0])<Integer.parseInt(line[1]))laptop1=true;
            else if(Integer.parseInt(line[0])>Integer.parseInt(line[1]))laptop2=true;
            
        }
        if(laptop1 && laptop2)out.println("Happy Alex");
        else out.println("Poor Alex");

        out.close();
    }

}
