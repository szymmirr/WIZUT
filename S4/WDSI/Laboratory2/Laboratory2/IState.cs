using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Laboratory2 {
    public interface IState : IComparable<IState> {
        #region Properties

        /// <summary>
        /// Minimalna gwarantowana wygrana dla gracza maksymalizującego.
        /// </summary>
        double Alpha { get; set; }

        /// <summary>
        /// Maksymalna gwarantowana wygrana dla gracza minimalizującego.
        /// </summary>
        double Beta { get; set; }

        /// <summary>
        /// Zwraca i ustawia potomków danego stanu.
        /// </summary>
        List<IState> Children { get; set; }

        /// <summary>
        /// Zwraca lub ustawia głębokość stanu w drzwie.
        /// </summary>
        double Depth { get; set; }

        /// <summary>
        /// Zwraca f. f = g + h.
        /// </summary>
        double F { get; }

        /// <summary>
        /// Zwraca i ustawia g - koszt osiągnięca wybranego stanu.
        /// </summary>
        double G { get; set; }

        /// <summary>
        /// Zwraca h - heurystyczną wartość dla stanu.
        /// </summary>
        double H { get; }

        /// <summary>
        /// Nazwa statnu jednoznacznie go identyfikująca. 
        /// </summary>
        string ID { get; }

        /// <summary>
        /// Definiuje czy wybrany stan jest dostępnu. W grach jak sudoku wybrany stan może być nie osiągalny.
        /// </summary>
        bool IsAdmissible { get; }

        /// <summary>
        /// Zwraca i ustawia przodka danego stanu.
        /// </summary>
        IState Parent { get; set; }

        /// <summary>
        /// Zwraca lub ustawia zazwę początkowego ruchu pozwalającego na dojście do tego stanu.
        /// </summary>
        string RootMove { get; set; }

        #endregion //end Properties

        #region Methods

        /// <summary>
        /// Oblicza h - heurystyczną wartość dla danego stanu.
        /// </summary>
        /// <returns>Heurystyczna wartość.</returns>
        double ComputeHeuristicGrade();

        #endregion //end Methods  
    }
}
