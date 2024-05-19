<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Document</title>
    </head>
    <body>    
            
        <?php 
           $sir=array(1=>'ion', 2=>'adi', 3=>125); 
           echo $sir[0]."<br>"; // afişează 
           echo $sir[1]."<br>"; // afişează 'ion' (string) 
           echo $sir[2]."<br>"; // afişează 'adi' (string) 
           echo $sir[3]."<br>"; // afişează 125 (intreg) 
           $sir[3]++; // incrementează
           echo $sir[3]."<br>"; // afişează 126 (intreg) 
           
        ?>
        
    </body>
</html>