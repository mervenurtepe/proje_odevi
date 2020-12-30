# proje_odevi
algoritma ve proglama proje odevi
ÖZET: 3000 karakteri aşmayacak bir metin kullanıcı tarafından girilir.
Girilen metin yabancı karakterlerden temizlenir.
Bigram ve trigramlarin metinde kaç kez bulunduğu hesaplanır.
Verilen frekans değerleriyle hesaplama yapılır ve metnin dilinin Almanca 
mı yoksa İngilizce mi olduğu belirlenir.

YAPTIĞIMIZ ÇALIŞMALAR:
ADIM 1: 
-Kullanıcıdan metin almak için gets fonksiyonunu kullandık.
-İngilizce ve Almanca dillerinde verilen bigram ve trigramların frekans değerleri metinde kaç kez kullanıldığını hesapladık.




ADIM 2:
-Void filter _str(char[]); fonksiyonunu kullanarak kullanıcıdan alınan metinde yer alan yabancı karakterleri temizledik.
-Bu fonksiyon sayesinde char dizisindeki karakterler tek tek kontrol edildi bu sayede büyük harf(A-Z), küçük harf (a-z) veya boşluk (ASCII:32) dışındaki tüm karakterler boşluk karakteriyle yer değiştirdi.




ADIM 3:
-Girilen  metinde void calculate_frequencies_bi(char str[]) fonksiyonu ile 
her bir bigramın metinde kaç kez tekrar ettiğini hesapadık. 
Hesaplanan frekansaları calculated_frequencies[l] dizisine sırasıyla  yerleştirdik.
- Girilen metinde void calculate_frequencies_tri(char str[])  fonksiyonu ile 
 her bir trigramın metinde kaç kez tekrar ettiğini hesapladık. Hesaplanan 
 frekansaları 10. elemandan başlayacak şekilde calculated_frequencies[l-10] 
 dizisine sırasıyla yerleştirdik.
ADIM 4:
- void calculate_distances (); fonksiyonu ile öklit uzaklığını hesapladık.
- İlk olarak frequencies_eng dizisi ile, yani İngilizce dili için verilmiş olan frekans matrisi ile calculated_frequencies dizisi arasında uzaklık hesabı yaptık. İkinci olarak, frequencies_germ dizisi ile, yani Almanca dili için verilmiş olan frekans matrisi ile calculated_frequencies dizisi arasında uzaklık hesabı yaptık.Elde edilen değerler sırasıyla global “distances” dizisinde ilgili indise atadık.



ADIM 5:
-void detect_lang() fonksiyonunu kullanarak bu  fonksiyonda  distances[0] ve distances[1] değerlerini karşılaştırdık bu sayede metnin dilinin ingilizce değilse  almanca olduğu yazdırılıyor.










