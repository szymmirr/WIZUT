using System.Collections.Generic;
using System.Data.Entity;

namespace Sklep.Models
{
    public class ProductDatabaseInitializer : DropCreateDatabaseIfModelChanges<ProductContext>
    {
        protected override void Seed(ProductContext context)
        {
            GetCategories().ForEach(c => context.Categories.Add(c));
            GetProducts().ForEach(p => context.Products.Add(p));
        }

        private static List<Category> GetCategories()
        {
            var categories = new List<Category> {
                new Category
                {
                    CategoryID = 1,
                    CategoryName = "Kaski"
                },
                new Category
                {
                    CategoryID = 2,
                    CategoryName = "Buty"
                },
                new Category
                {
                    CategoryID = 3,
                    CategoryName = "Kurtki"
                },
                new Category
                {
                    CategoryID = 4,
                    CategoryName = "Rekawice"
                },
                new Category
                {
                    CategoryID = 5,
                    CategoryName = "Spodnie"
                },
            };

            return categories;
        }

        private static List<Product> GetProducts()
        {
            var products = new List<Product> {
                new Product
                {
                    ProductID = 1,
                    ProductName = "Kask Cross/Enduro Ispido Desert",
                    Description = "Kask został wyposażony w demontowalny daszek, przeźroczysty wizjer główny oraz wewnętrzną podnoszoną blendę przeciwsłoneczną. Dzięki temu spełnia wymagania motocyklistów enduro oraz ATV.",
                    ImagePath="ispido.png",
                    UnitPrice = 368.99,
                    CategoryID = 1
               },
                new Product
                {
                    ProductID = 2,
                    ProductName = "Kask Otwarty NEXX SX.10 Plain",
                    Description = "Nexx SX.10 to doskonała propozycja dla posiadaczy skuterów. Za pomocą wielokolorowych skorup i innych elementów zewnętrznych można go konfigurować kolorystycznie do swoich potrzeb.",
                    ImagePath="nexx.png",
                    UnitPrice = 239.99,
                     CategoryID = 1
               },
                new Product
                {
                    ProductID = 3,
                    ProductName = "Kask integralny Nolan N64 Aquarium",
                    Description = "N64 to podstawowy i najbardziej rozpoznawalny model. Zapewnia komfort jazdy, nie tylko podczas krótkich przejazdów przez miasto, ale również podczas dłuższych tras turystycznych. ",
                    ImagePath="nolan.png",
                    UnitPrice = 749.99,
                    CategoryID = 1
                },
                new Product
                {
                    ProductID = 4,
                    ProductName = "Kask integralny Shark Vancore",
                    Description = "Wyjątkowy kask integralny o wyjątkowym wyglądzie. Skorupa to jednolita bryła wraz z częścią szczękową. Skorupa została zaprojektowana tak, aby była dopasowana do kształtu czaszki.",
                    ImagePath="vancore.png",
                    UnitPrice = 599.99,
                    CategoryID = 1
                },
                new Product
                {
                    ProductID = 5,
                    ProductName = "Kask integralny Shark D-SKWAL Hiwo",
                    Description = "Posiada system wentylacji. Komfort użytkowania podnosi także zastosowany system „Autoseal”. To funkcja, za pomocą której wizjer jest dodatkowo dociskany do uszczelki. ",
                    ImagePath="hiwo.png",
                    UnitPrice = 898.99,
                    CategoryID = 1
                },
                new Product
                {
                    ProductID = 6,
                    ProductName = "Buty Turystyczne New Land GORE-TEX Alpinestars",
                    Description = "Krótkie wygodne i wszechstronne buty turystyczne które wykonano z najwyższej jakości skóry. Wodoodporne i oddychające dzięki zastosowaniu membrany GORE-TEX.",
                    ImagePath="butytur.png",
                    UnitPrice = 898.99,
                    CategoryID = 2
                },
                new Product
                {
                    ProductID = 7,
                    ProductName = "Buty codzienne Stella Faster 2 Alpinestars",
                    Description = "Lekka podeszwa pozwala na doskonałe czucie dźwigni i jednocześnie zapewnia najwyższy poziom wygody po zejściu z motocykla. Posiada boczny ochraniacz typu slider.",
                    ImagePath="butycodzienne.png",
                    UnitPrice = 579.99,
                    CategoryID = 2
                },
                new Product
                {
                    ProductID = 8,
                    ProductName = "Buty CROSS/ENDURO Tech 7 Alpinestars MX ",
                    Description = "Posiadające certyfikat CE buty promują stabilność w rdzeniu, przy zachowaniu odpowiedniej elastyczność dzięki biomechanicznemu zawiasowi.",
                    ImagePath="butycross.png",
                    UnitPrice = 1599.99,
                    CategoryID = 2
                },
                new Product
                {
                    ProductID = 9,
                    ProductName = "Buty sportowe Supertech R Alpinestars",
                    Description = "Najwyższy model wyścigowych butów Alpinestars, któremu zaufało wielu zawodników – Mistrzów Świata WSBK, MotoGP i innych serii wyścigowych.",
                    ImagePath="butysp.png",
                    UnitPrice = 1349.99,
                    CategoryID = 2
                },
                new Product
                {
                    ProductID = 10,
                    ProductName = "Kurtka tekstylna Alpinestars Cordoba",
                    Description = "Dwuwarstwowa kurtka turystyczna Cordoba czerpie z najlepszych rozwiązań stosowanych przez Alpinestars w wyższych seriach. Wodoodporna oddychająca membrana DRYSTAR zintegrowana jest z warstwą zewnętrzną wykonaną z Poliestru 600 D.",
                    ImagePath="kurtkaalp.png",
                    UnitPrice = 499.99,
                    CategoryID = 3
                },
                new Product
                {
                    ProductID = 11,
                    ProductName = "Kurtka turystyczna Macna Orient",
                    Description = "Damska kurtka skórzana, do jazdy w cieplejszych porach roku. Materiałem, z którego została wykonana to bydlęca skóra, uzupełniona w wielu miejscach elastycznym materiałem Dynamic.",
                    ImagePath="kurtkamacna.png",
                    UnitPrice = 779.99,
                    CategoryID = 3
                },
                new Product
                {
                    ProductID = 12,
                    ProductName = "Kurtka tekstylna Ixon Eager",
                    Description = "Doskonale komponować się będzie z motocyklami sportowymi i naked. Wypinana podpinka ocieplająca na chłodniejsze dni, i wbudowana oddychająca membrana na zmienną letnią pogodę.",
                    ImagePath="kurtkaixon.png",
                    UnitPrice = 389.99,
                    CategoryID = 3
                },
                new Product
                {
                    ProductID = 13,
                    ProductName = "Rękawice CROSS/ENDURO Fly Racing F-16",
                    Description = "Rękawice serii F-16 zostały wykonane z elastycznych materiałów, niekrępujących ruchów i zapewniających doskonałe czucie manetek. Idealne na ostry teren.",
                    ImagePath="rekawcross.png",
                    UnitPrice = 49.99,
                    CategoryID = 4
                },
                new Product
                {
                    ProductID = 14,
                    ProductName = "Rękawice turystyczne Ixon Pro LEVEL 2",
                    Description = "Ciepłe wodoodporne rękawice zalecane do stosowania wczesną wiosna i jesienią. We wnętrzu znajduje się wodoodporna i oddychająca membrana i ciepła wyściółka",
                    ImagePath="rekawtur.png",
                    UnitPrice = 139.99,
                    CategoryID = 4
                },
                new Product
                {
                    ProductID = 15,
                    ProductName = "Rękawice sportowe Alpinestars Scheme Kevlar",
                    Description = "Szosowe rękawice tekstylne, wzmocnione elementami ze skóry. Wykonane z Kevlaru optymalnie zabezpieczają szczególnie narażone na przetarcia miejsca.",
                    ImagePath="rekawsport.png",
                    UnitPrice = 269.99,
                    CategoryID = 4
                },
                new Product
                {
                    ProductID = 16,
                    ProductName = "Spodnie Macna Mercury",
                    Description = "Nowe, całosezonowe tekstylne spodnie turystyczne. Posiadają oddychającą membranę wodoodporną i wypinaną podpinkę ocieplającą.",
                    ImagePath="spodnie.png",
                    UnitPrice = 379.99,
                    CategoryID = 5
                }
            };

            return products;
        }
    }
}