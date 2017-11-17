import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLEncoder;
import java.security.cert.Certificate;
import java.io.*;
import javax.net.ssl.HttpsURLConnection;
import javax.net.ssl.SSLPeerUnverifiedException;


public class HttpsPost2{

	//static String https_url = "https://portaldemo.dattus.com/app/#/";
	//static String https_url = "https://httpbin.org/";
	static String https_url = "https://posttestserver.com/post.php?dir=Buga";
	static String file_location = "SampleStory.txt";
	static String buffer="";

	public static void main(String[] args) {

		System.out.println("Running POST request on "+https_url);
		new HttpsPost2().testIt();
	}

	public void testIt(){
		
		URL myurl;
		BufferedReader bufferedReader = null;
		FileReader fileReader = null;

		try{

			//String query = "email="+URLEncoder.encode(email,encoding)+"&"+"password="+URLEncoder.encode(password,encoding);

			myurl = new URL(https_url);

			HttpsURLConnection con = (HttpsURLConnection)myurl.openConnection();
			con.setRequestMethod("POST");

			//con.setRequestProperty("Content-length", String.valueOf(query.length())); 
			con.setRequestProperty("Content-Type","application/x-www-form-urlencoded"); 
			con.setRequestProperty("User-Agent", "Mozilla/4.0 (compatible; MSIE 5.0;Windows98;DigExt)"); 
			con.setDoOutput(true);
			con.setDoInput(true);

			DataOutputStream output = new DataOutputStream(con.getOutputStream());  


			fileReader=new FileReader(file_location);
			bufferedReader=new BufferedReader(fileReader);
			String sCurrentLine;
			bufferedReader=new BufferedReader(new FileReader(file_location));

			while ((sCurrentLine = bufferedReader.readLine()) != null) {
				output.writeBytes(sCurrentLine);
			}

			output.close();

			DataInputStream input = new DataInputStream( con.getInputStream() ); 



			for( int c = input.read(); c != -1; c = input.read() ) 
				System.out.print( (char)c ); 
			input.close(); 

			System.out.println("Resp Code:"+con .getResponseCode()); 
			System.out.println("Resp Message:"+ con .getResponseMessage()); 
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
}