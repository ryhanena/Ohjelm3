Konsta Könönen, 267400
Antti Ryhänen, 275130

Pirkanmaan valloitus
Pelin idea ja säännöt:
Pelin alussa käynnistyy dialog-ikkuna, josta valitaan pelaajien määrä (2-4), kartan koko (7-10 ruutua) ja ruutujen koko (50-200). Lisäksi dialogista valitaan pelin pisin mahdollinen pituus (10-100). Painamalla OK peli voidaan aloittaa. Dialogin poistuttua aukeaa vasemmalla pelikenttä ja oikealla toiminnot, sekä pelaajat ja niiden resurssit. Pelin alussa pelaajat aloittavat kartan kulmista ja heille rakennetaan päärakennukset. Lisäksi pelaajille on määritetty seuraavat aloitusresurssit.
Raha(M) 	= 200
Ruoka(F)	= 200
Puu(W)		= 100
Kivi(S)		= 100
Malmi(O)	= 50

Peli on vuoropohjainen ja vuoro koostuu joko liikkumisesta tai rakennuksen rakentamisesta. Pelaajan toiminto voi ulottua ainoastaan viereiseen ruutuun. Rakentaminen tai työntekijöiden asettaminen onnistuu painamalla pohjaan halutun napin ja lisäämällä sen kartalle hiiren painalloksella. Kaikkiin ruutuihin on mahdollista siirtyä, lukuun ottamatta järveä. Aavikolle ei puolestaan pysty rakentamaan mitään muuta kuin pommin ja kalastajan pystyy lisäämään ainoastaan järveen, jonne ei muita rakennuksia tai työntekijöitä pysty lisäämään. 

Pelin pohjimmaisena ideana on voittaa muut pelaajat kerryttämällä resursseja enemmän kuin muut. Resursseja saa eri määrän eri laatoilta. Laattojen resurssientuotanto kasvaa, mikäli niille lisätään rakennuksia tai työläisiä. Lisäksi pelin voi voittaa tuhoamalla muut vastustajat pommittamalla heidän päämajansa, pommilla voi tuhota myös muita rakennuksia ja työntekijöitä. Rakennusten suojelemiseksi pelissä on vartio. Mikäli ruudussa on jonkun toisen pelaajan asettama varto, ruutuun ei voi liikkua, eikä asettaa pommia. Vartion voi kuitenkin pommittaa asettamalla pommin viereiseen ruutuun. Pelin loppuessa jäljellä olevien pelaajien resurssit lasketaan yhteen pisteiksi ja eniten pisteitä kerännyt pelaaja voittaa pelin. 

Pelin ratketessa näytölle ilmestyy lopetusdialogi, joka näyttää jälellä olevien pelaajien resurssit ja voittajan. Lopetusdialogin sulkeuduttua myös pääohjelman suoritus loppuu.

Pelin laatat + perustuotot (M,F,W,S,O):
Ruohikko 	(2,5,1,1,0)
Metsä		(1,3,5,1,0)
Aavikko		(0,0,0,1,0)
Järvi		(2,5,0,0,0)
Vuori		(3,0,0,3,3)

Pelin rakennukset + tuotot (M,F,W,S,O) + hinta (M,F,W,S,O):
Päämaja		(10,2,0,0,0)			()
Farmi		(1,5,0,0,0)			(50,100,25,0,0)
Kaivos		(5,0,0,10,0)			(50,100,50,100,0)
Vartio		(-5,-2,0,0,0)			(150,200,200,25,0)
Pommi		()				(100,100,100,100,10)

Pelin työntekijät + tuotot (M,F,W,S,O) + Hinta (M,F,W,S,O):
Täytemies	(0.25,1.00,0.75,0.5,0.5)	(10,25,0,0,0)
Insinööri	(2.00,2.00,2.00,2.00,2.00)	(100,25,0,0,0)
Kalastaja	(1.00,3.00,0,0,0)		(50,25,100,0,0)

Toteutetut lisäosat:
	Rakennukset:
		-Kaivos
		-Pommi
	Maalaatat:
		-Aavikko
		-Järvi
		-Vuori
	Työntekijät:
		-Insinööri
		-Kalastaja

Lisäksi peliin on toteutettu ohjeikkuna peliohjeille, sekä resurssinäkymä pelinaikaisten resurssihintojen tutkimiselle. Peliin on toteutettu myös lopetusdialogi, mikä näyttää pelin lopputuloksen. 




