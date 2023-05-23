package ex_0;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Persoana {
	
	// members
	private String nume_prenume;
	private LocalDate data_nasterii;
	private String adresa;
	private String telefon;
	
	// constructors
	public Persoana(String nume_prenume, LocalDate data_nasterii, String adresa, String telefon) {
		super();
		this.nume_prenume = nume_prenume;
		this.data_nasterii = data_nasterii;
		this.adresa = adresa;
		this.telefon = telefon;
	}
	
	public Persoana() {}
	
	
	
	// getters & setters
	public String getNume_prenume() {
		return nume_prenume;
	}

	public void setNume_prenume(String nume_prenume) {
		this.nume_prenume = nume_prenume;
	}

	public LocalDate getData_nasterii() {
		return data_nasterii;
	}

	public void setData_nasterii(LocalDate data_nasterii) {
		this.data_nasterii = data_nasterii;
	}

	public String getAdresa() {
		return adresa;
	}

	public void setAdresa(String adresa) {
		this.adresa = adresa;
	}

	public String getTelefon() {
		return telefon;
	}

	public void setTelefon(String telefon) {
		this.telefon = telefon;
	}
	
	
	
	// methods
	@Override
	public String toString() {
		
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
		
		return 
			String.format(
			"""
				<tr>
					<td>%s</td>
					<td>
					
				</tr>
					
					""", 
			nume_prenume, LocalDate., adresa, telefon);
	}
	

}
