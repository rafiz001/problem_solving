/*
 * Problem: Watermelon
 * URL: https://codeforces.com/problemset/problem/4/A
 * 
 * Description:
 * Given an integer number of the weight of watermelon, have to print whether it can be devided into two even number of the weight.
 * Constraints: 1 ≤ w ≤ 100
 * 
 * Approach:
 * 
 */

import java.io.*;

public class Watermelon {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int w = Integer.parseInt(br.readLine().trim());
        if(w > 2 && (w&1)==0)
            out.println("Yes");
        else
            out.println("No");

        out.close();
    }


}