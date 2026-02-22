

# C++ & SQL Server: Finansal Veri Entegrasyonu ve Analiz

Bu proje, C++ programlama dili ile Microsoft SQL Server arasında bir veri köprüsü kurarak, finansal veri simülasyonu ve temel istatistiksel analizler gerçekleştirmek amacıyla geliştirilmiştir.

## 🚀 Proje Amacı
Bu çalışmada, piyasa verilerini taklit eden rastgele fiyatlar üretilmiş, bu veriler bir ilişkisel veritabanında saklanmış ve SQL'in hesaplama gücü kullanılarak analiz sonuçları C++ konsoluna geri çekilmiştir.

## 🛠️ Özellikler
- **ODBC Bağlantısı:** Windows ODBC sürücüleri kullanılarak SQL Server ile düşük seviyeli (low-level) güvenli bağlantı.
- **Veri Simülasyonu:** `for` döngüsü ve rastgele sayı üreticileri ile 100 adet gerçekçi piyasa fiyatı (BTC örneği) üretimi.
- **SQL Entegrasyonu:** `INSERT` sorguları ile verilerin anlık olarak veritabanına kaydedilmesi.
- **İstatistiksel Analiz:** SQL `AVG()` fonksiyonu ile tüm geçmiş verilerin ortalamasının C++ tarafında hesaplanması (`SQLBindCol` ve `SQLFetch` kullanımı).

## 🧰 Kullanılan Teknolojiler
- **Dil:** C++
- **Veritabanı:** Microsoft SQL Server (MS SQL)
- **Kütüphane:** Windows ODBC (odbc32.lib)
- **Geliştirme Ortamı:** Visual Studio 2022

## 📝 Öğrenilen Teknik Detaylar
Bu süreçte aşağıdaki teknik zorluklar çözülmüştür:
- **Karakter Setleri:** Unicode ve Multi-Byte karakter setleri arasındaki farklar ve `SQLDriverConnectA` kullanımı.
- **Linker Ayarları:** Dış kütüphanelerin (`.lib`) projeye dahil edilmesi.
- **Hata Yönetimi:** Bağlantı hataları ve SQL imleç (cursor) yönetimi.

---
*Bu proje, yazılım geliştirme sürecinde yapay zeka asistanlığı ve mühendislik mantığının birleşimiyle öğrenme amacıyla oluşturulmuştur.*
