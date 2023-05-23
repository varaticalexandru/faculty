package ex_1;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Calcul
 */
@WebServlet("/Calcul")
public class Calcul extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Calcul() {
        super();
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String n1 = request.getParameter("nr1");
		String n2 = request.getParameter("nr2");
		
		PrintWriter pw = response.getWriter();
		pw.println(
				"""
				<html>
				
					<head>
						<title>Suma</title>
					</head>
					
					<body>
				""");
		
		if (n1 == null || n2 == null) {
			pw.println("Rulati mai intai fisierul numere.html</body></html>");
		} else {
			
			try {
				
				int x = Integer.parseInt(n1);
				int y = Integer.parseInt(n2);
				
				int suma = x + y;
				
				pw.println("Suma: " + suma + "</body></html>");
				
			} catch (Exception e) {
				
				pw.println("Valori lipsa sau in format necorespunzator</body></html>");
			}
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
