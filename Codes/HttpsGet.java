import java.net.MalformedURLException;
import java.net.URL;
import java.security.cert.Certificate;
import java.io.*;

import javax.net.ssl.HttpsURLConnection;
import javax.net.ssl.SSLPeerUnverifiedException;

public class HttpsGet{

	static String https_url = "https://portaldemo.dattus.com/app/api/settings/sensor";

	public static void main(String[] args)
   	{
   		System.out.println("Running GET request on "+https_url);
        new HttpsGet().testIt();
   	}

   	private void testIt(){

    	URL url;
      	try {

	     	url = new URL(https_url);
	     	HttpsURLConnection con = (HttpsURLConnection)url.openConnection();
	     	con.setRequestMethod("GET");
	     	con.setRequestProperty("Authorization", "basic"); 
			con.setRequestProperty("api-key","48918482f384448d8879c3e84c33b6f2"); 
			con.setRequestProperty("Connection", "close"); 
			//con.setDoOutput(true);
			//con.setDoInput(true);

	     	//dumpl all cert info
	     	print_https_cert(con);

	     	//dump all the content
	     	print_content(con);

      	} catch (MalformedURLException e) {
	     	e.printStackTrace();
      	} catch (IOException e) {
	     	e.printStackTrace();
      	}
   }

   private void print_https_cert(HttpsURLConnection con){

    if(con!=null){

      try {

	System.out.println("Response Code : " + con.getResponseCode());
	System.out.println("Cipher Suite : " + con.getCipherSuite());
	System.out.println("\n");

	Certificate[] certs = con.getServerCertificates();
	for(Certificate cert : certs){
	   System.out.println("Cert Type : " + cert.getType());
	   System.out.println("Cert Hash Code : " + cert.hashCode());
	   System.out.println("Cert Public Key Algorithm : "
                                    + cert.getPublicKey().getAlgorithm());
	   System.out.println("Cert Public Key Format : "
                                    + cert.getPublicKey().getFormat());
	System.out.println("\n******************* CERTIFICATE ****************** \n"+ cert);
	   System.out.println("\n");
	}

	} catch (SSLPeerUnverifiedException e) {
		e.printStackTrace();
	} catch (IOException e){
		e.printStackTrace();
	}

     }

   }

   private void print_content(HttpsURLConnection con){
	if(con!=null){

	try {

	   	System.out.println("****** Content of the URL ********");
	   	BufferedReader br =new BufferedReader(new InputStreamReader(con.getInputStream()));

	   	String input;

	   	while ((input = br.readLine()) != null){
	   		System.out.println(input);
	   	}
	   	br.close();

	} catch (IOException e) {
	   e.printStackTrace();
	}

       }

   }

}
