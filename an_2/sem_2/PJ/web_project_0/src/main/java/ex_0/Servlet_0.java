package ex_0;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Servlet_0
 */
@WebServlet("/Servlet_0")
public class Servlet_0 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public Servlet_0() {
        super();
        // TODO Auto-generated constructor stub
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		
		PrintWriter pw = response.getWriter();
		
		pw.println("""
				<html>
					<head>
						<title>Primul servlet</title>
					</head>
					
					<body>
						Buna !
					</body>
					
				</html>
				""");
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
