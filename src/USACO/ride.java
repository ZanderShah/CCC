package USACO;
/*
ID: zander.1
LANG: JAVA
PROG: ride
*/
import java.io.*;
import java.util.*;
class ride {
  public static void main (String [] args) throws IOException {
    BufferedReader f = new BufferedReader(new FileReader("ride.in"));                                            
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ride.out")));
    //StringTokenizer st = new StringTokenizer(f.readLine());
						 
    String comet = f.readLine();   
    String group = f.readLine();     
 
    int c = 1;
    int g = 1;
    
    for (int i = 0; i < comet.length(); i++)
    	c *= comet.charAt(i) - 'A' + 1;
    
    for (int i = 0; i < group.length(); i++)
    	g *= group.charAt(i) - 'A' + 1;
    
    if (c % 47 == g % 47)
    	out.println("GO");
    else
    	out.println("STAY");
 
    out.close();                                  
    System.exit(0);                               
  }
}
