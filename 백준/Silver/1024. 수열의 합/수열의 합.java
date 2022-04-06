import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());

        boolean isArrExist = false;
        int len = l;
        int tmp;
        while(!isArrExist) {
            tmp = n - (len * (len - 1)) / 2;
            if(tmp < 0 || len > 100) {
                isArrExist = false;
                break;
            }

            if(tmp % len == 0) {
                isArrExist = true;
                break;
            }
            else {
                len++;
            }
        }
        
        if(!isArrExist) {
            bw.write(String.valueOf(-1));
            bw.flush();
            
            br.close();
            bw.close();
        }
        else {
            ArrayList<Integer> arr = new ArrayList<>();
            for(int i = 0; i < len; i++) {
                arr.add(((n - (((len - 1) * len) / 2)) / len) + i);
            }
    
            for(int i = 0; i < arr.size(); i++) {
                if(i == 0) {
                    bw.write(String.valueOf(arr.get(i)));
                }
                else {
                    bw.write(String.valueOf(" " + arr.get(i)));
                }
            }
    
            bw.flush();
            
            bw.close();
            br.close();
        }
    }

}
