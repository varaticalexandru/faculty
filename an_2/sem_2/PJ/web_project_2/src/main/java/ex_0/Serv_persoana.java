package ex_0;

import java.io.IOException;
import java.io.PrintWriter;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

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
	
	// members
	private static final long serialVersionUID = 1L;
	Set<Persoana> persoane = new HashSet<Persoana>();	// set de persoane
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Serv_persoana() {
        super();
    }
    
    public int getOrder(String s)
	{
		switch(s)
		{
			case "ianuarie" ->{return 1;}
			case "februarie" ->{return 2;}
			case "martie" ->{return 3;}
			case "aprilie" ->{return 4;}
			case "mai" ->{return 5;}
			case "iunie" ->{return 6;}
			case "iulie" ->{return 7;}
			case "august" ->{return 8;}
			case "septembrie" ->{return 9;}
			case "octombrie" ->{return 10;}
			case "noiembrie" ->{return 11;}
			case "decembrie" ->{return 12;}
			default -> {return 0;}
		}
	}
    
    

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	
		doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		
		if (request.getParameter("vizualizare") == null) {	// nu a fost apasat butonul de vizualizare
			
			// adaugarea persoanei din request + afisarea intregului set de persoane
			
			
			PrintWriter pw = response.getWriter();
			
			// fetch data form request
			String nume_prenume = request.getParameter("nume_prenume");
			String zi = request.getParameter("zi");
			String luna = request.getParameter("luna");
			String an = request.getParameter("an");
			String adresa = request.getParameter("adresa");
			String telefon = request.getParameter("telefon");
			
			LocalDate data_nasterii = LocalDate.of(Integer.parseInt(an), Integer.parseInt(luna), Integer.parseInt(zi));
			
			Persoana persoana = new Persoana(nume_prenume, data_nasterii, adresa, telefon);
			
			persoane.add(persoana);
			
			pw.println("""
					<html>
					
						<head>
							<title>Persoanele adaugate</title>
						<head>
						
						<body>
						
							<h2>Persoanele introduse</h2>
							
							<table border='1'>
								<tr>
									<th>Nume si prenume</th>
									<th>Data nasterii</th>
									<th>Adresa</th>
									<th>Telefon</th>
								</tr>
							
							
						""");
				
				
				
				// afisare set persoane
				for (Persoana p : persoane) {
					pw.println(p);
				}
				
				
				pw.println(
						"""
						</table>
						""");
				
				
				pw.println(
						"""
							<form method='POST' action='Serv_persoana'>
								<select name='luna'>
									<option value='ianuarie'>Ianuarie</option>
									<option value='februarie'>Februarie</option>
									<option value='martie'>Martie</option>
									<option value='aprilie'>Aprilie</option>
									<option value='mai'>Mai</option>
									<option value='iunie'>Iunie</option>
									<option value='iulie'>Iulie</option>
									<option value='august'>August</option>
									<option value='septembrie'>Septembrie</option>
									<option value='octombrie'>Octombrie</option>
									<option value='noiembrieNoiembrie</option>
								    <option value='decembrie'>Decembrie</option>
								</select>
							
								<input type='submit' name='vizualizare' value='Vizualizare'>
							</form>
						
						""");
				
				
				
				
				
				pw.println("""
						</body>
						
					</html>
						""");
			
			
		}
		else {	// a fost apasat butonul de vizualizare
			
			PrintWriter pw = response.getWriter();
			
			// fetch data form request
			String luna = request.getParameter("luna");
			
			
			pw.println("""
					<html>
					
						<head>
							<title>Persoanele adaugate</title>
						<head>
						
						<body>
						
							<h2>Persoanele introduse</h2>
							
							<table border='1'>
								<tr>
									<th>Nume si prenume</th>
									<th>Data nasterii</th>
									<th>Adresa</th>
									<th>Telefon</th>
								</tr>
							
							
						""");
			
			
			// afisarea persoanelor care sunt nascute in luna selectata
			for (Persoana p : persoane) {
				
				if (p.getData_nasterii().getMonthValue() == getOrder(luna)) {
					pw.println(p);
				}
			}
			
			
			pw.println(
					"""
					</table>
					""");
			
			
			
			pw.println("""
					</body>
					
				</html>
					""");
		}
		
		
	}

}
