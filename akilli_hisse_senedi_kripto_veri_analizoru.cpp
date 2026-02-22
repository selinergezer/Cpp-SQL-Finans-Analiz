


#include <Windows.h>
#include <iostream>
#include <sql.h>
#include <sqlext.h>
#include <string>

int main()
{
    std::cout << "Program baslatildi...";
    
    SQLHENV hEnv=NULL; //SQL orteam tutucu
    SQLHDBC hDbc=NULL; //Bağlantı tutucu
    SQLHSTMT hStmt=NULL; //Sorgu tutucu
    SQLRETURN ret; //Dönüş değerlerini kontrol etmek için
    
    std::cout << "SQL ortami hazirlaniyor...\n";
   
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

    std::cout << "SQL Server'a baglaniliyor...\n";

    SQLCHAR connStr[] = "Driver={SQL Server};Server=.;Database=FinansTest;Trusted_Connection=yes;";
    ret = SQLDriverConnect(hDbc, NULL, connStr, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_NOPROMPT);

    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
        std::cout << "Baglanti basarili,100 veri uretiliyor...\n";
        SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);

        for (int i = 0; i < 100; i++) {
            double rastgeleFiyat = 50000 + (rand() % 20000);
            std::string queryStr = "INSERT INTO PiyasaVerisi (Sembol,Fiyat) VALUES ('BTC', " + std::to_string(rastgeleFiyat) + ")";
            SQLExecDirectA(hStmt, (SQLCHAR*)queryStr.c_str(), SQL_NTS);

            SQLCloseCursor(hStmt);
        }

        std::cout << "Veriler hazir.Ortalama hesaplaniyor...\n";
       
        SQLCHAR* analizSorgusu = (SQLCHAR*)"SELECT AVG(Fiyat) FROM PiyasaVerisi";
        SQLExecDirectA(hStmt, analizSorgusu, SQL_NTS);

        double ortalamaFiyat = 0;
        SQLBindCol(hStmt, 1, SQL_C_DOUBLE, &ortalamaFiyat, 0, NULL);
        if (SQLFetch(hStmt) == SQL_SUCCESS) {
          std::cout << "------------------------------------------\n";
          std::cout << "ANALIZ SONUCU: Tum verilerin ortalamasi: " << ortalamaFiyat << " USD\n";
          std::cout << "------------------------------------------\n";
        }
        SQLCloseCursor(hStmt);  
    }
    else {
        std::cout << "Bağlanti Hatasi...\n";
    }
    if (hStmt) SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    if (hDbc) {
        SQLDisconnect(hDbc);
        SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    }
    if (hEnv) SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

    std::cout << "\nIslem bitti. Kapatmak icin ENTER tusuna basin...";
    std::string beklet;
    std::cin >> beklet;

    return 0;

}
