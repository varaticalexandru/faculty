package ex_0;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Serv_persoana
 */
@WebServlet("/Serv_persoana")
public class Serv_persoana extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
   
    public Serv_persoana() {
        super();
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		PrintWriter out = response.getWriter();
		
		out.println("""
				<html>
					<head>
						<title>Adaugare informatii</title>
					</head>

					<body>
						
						<h1>Adaugare Informatii</h1>
						
						<form method = 'POST' action='Serv_persoana'>
							<p>
								<b>Nume si prenume</b>
								<input type='text' name='nume_prenume'>
							</p>
							
							<p>
								<b>Data nasterii (zi,luna,an)</b>
								<input type='text' name='data_nasterii'>
							</p>
							
							<p>
								<b>Adresa</b>
								<input type='text' name='adresa'>
							</p>
							
							<p>
								<b>Telefon</b>
								<input type='text' name='telefon'>
							</p>
							
							<p>
								<input type='submit' name='adaugare'>
							</p>
						</form>
		""");
		
		
		
		
	
		
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		PrintWriter out = response.getWriter();
		
		String nume_prenume = request.getParameter("nume_prenume");
		String data_nasterii = request.getParameter("data_nasterii");
		String adresa = request.getParameter("adresa");
		String telefon = request.getParameter("telefon");
		
		

	}

}
