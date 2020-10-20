using System;
using System.Collections.Generic;
using System.Text;

namespace Laboratory2 {
    public abstract class AlphaBetaSearcher {

        #region Private Fileds

        /// <summary>
        /// Decyduje cze gracz maksymalizujący ma pierwszy ruch.
        /// </summary>
        protected readonly bool isMaximizingPlayerFirst;

        /// <summary>
        /// Przetrzymuje oceny (mini-max) aktualnie analizowanego ruchu.
        /// String reprezentuje ruch.
        /// </summary>
        private Dictionary<string, double> movesMiniMaxes = null;

        /// <summary>
        /// Makzymalna głębokość.
        /// </summary>
        protected readonly double maximumDepth;

        /// <summary>
        /// Stan startowy.
        /// </summary>
        protected IState startState = null;

        /// <summary>
        /// Ponowne użycie stanów już raz odwiedzonych.
        /// </summary>
        public int useOfVisited = 0;

        /// <summary>
        /// Przechowuje odwiedzone stany.
        /// </summary>
        protected Dictionary<string, IState> visited = null;

        #endregion //end Private Fileds

        #region Properties

        /// <summary>
        /// Makzymalna głębokość.
        /// </summary>
        public int MaximumDepth {
            get {
                return (int)this.maximumDepth;
            }
        }

        /// <summary>
        /// Zwraca ruchy mini-max.
        /// </summary>
        public Dictionary<string, double> MovesMiniMaxes {
            get {
                return this.movesMiniMaxes;
            }
        }

        /// <summary>
        /// Zwraca stany odwiedzone.
        /// </summary>
        public Dictionary<string, IState> Visited {
            get {
                return this.visited;
            }
        }

        #endregion //end Properties

        #region Constructors

        /// <summary>
        /// Konstruktor.
        /// </summary>
        /// <param name="startState">Stan początkowy.</param>
        /// <param name="isMaximizingPlayerFirst">Wybór gracza startowego.</param>
        /// <param name="maximumDepth">Maksymalna głębokość.</param>
        public AlphaBetaSearcher(IState startState, bool isMaximizingPlayerFirst, double maximumDepth) {
            this.startState = startState;
            this.isMaximizingPlayerFirst = isMaximizingPlayerFirst;
            this.maximumDepth = maximumDepth;
            this.movesMiniMaxes = new Dictionary<string, double>();
            this.visited = new Dictionary<string, IState>();
        }

        #endregion //end Constructors

        #region Protected Methods

        /// <summary>
        /// Tworzenie stanów potomków dla podanego stanu rodzicielskiego.
        /// </summary>
        /// <param name="parent">Stan rodzicielski.</param>
        protected abstract void buildChildren(IState parent);

        /// <summary>
        /// Oblicza stan maksymalizujący
        /// </summary>
        /// <param name="state">Stan.</param>
        /// <param name="alpha">Wartość Alfa.</param>
        /// <param name="beta">Wartość Beta.</param>
        /// <param name="depth">Głębokość.</param>
        /// <returns>Nowa wartość Alfa.</returns>
        protected double evaluateMaxState(IState state, double alpha, double beta, double depth) {
            double startAlpha = alpha;
            double startBeta = beta;

            double grade = state.ComputeHeuristicGrade();
            string key;

            if (double.IsInfinity(grade) || depth >= this.maximumDepth) {
                state.Alpha = grade;
                state.Beta = grade;
                
                key = state.ID + ";" + startAlpha + ";" + startBeta + ";" + state.Depth;

                if (this.visited.ContainsKey(key)) {
                    this.visited[key] = state;
                }
                else {
                    this.visited.Add(key, state);
                }

                return grade;
            }

            double tempAlpha = double.NegativeInfinity;

            buildChildren(state);

            List<IState> children = state.Children;

            for (int i = 0; i < children.Count; i++) {
                IState child = children[i];

                key = child.ID + ";" + alpha + ";" + beta + ";" + child.Depth;

                //depth is a part of the hashCode
                if (this.visited.ContainsKey(key)) {
                    tempAlpha = visited[key].Beta;
                    this.useOfVisited++;
                }
                else {
                    tempAlpha = evaluateMinState(child, alpha, beta, depth + 0.5);
                }


                if (tempAlpha > alpha) {
                    alpha = tempAlpha;
                    //we are at the top of the tree
                    if (state.Parent == null) {
                        if (this.movesMiniMaxes.ContainsKey(child.RootMove)) {
                            this.movesMiniMaxes[child.RootMove] = tempAlpha;
                        }
                        else {
                            this.movesMiniMaxes.Add(child.RootMove, tempAlpha);
                        }
                    }
                }

                //pruning condition
                if (alpha >= beta) {
                    break;
                }
            }

            state.Alpha = alpha;
            state.Beta = beta;

            key = state.ID + ";" + startAlpha + ";" + startBeta + ";" + state.Depth;
            if (this.visited.ContainsKey(key)) {
                this.visited[key] = state;                
            }
            else {
                this.visited.Add(key, state);
            }

            return alpha;
        }

        /// <summary>
        /// Oblicza stan minimalizujący.
        /// </summary>
        /// <param name="state">Stan.</param>
        /// <param name="alpha">Wartość Alfa.</param>
        /// <param name="beta">Wartość Beta.</param>
        /// <param name="depth">Głębokość.</param>
        /// <returns>Nowa wartość Beta.</returns>
        protected double evaluateMinState(IState state, double alpha, double beta, double depth) {
            double startAlpha = alpha;
            double startBeta = beta;

            double grade = state.ComputeHeuristicGrade();
            string key;

            if (double.IsInfinity(grade) || depth >= this.maximumDepth) {
                state.Alpha = grade;
                state.Beta = grade;

                key = state.ID + ";" + startAlpha + ";" + startBeta + ";" + state.Depth; 
                
                if (this.visited.ContainsKey(key)) {
                    this.visited[key] = state;
                }
                else {
                    this.visited.Add(key, state);
                }

                return grade;
            }

            double tempBeta = double.PositiveInfinity;

            buildChildren(state);
            List<IState> children = state.Children;

            for (int i = 0; i < children.Count; i++) {
                IState child = children[i];

                key = child.ID + ";" + alpha + ";" + beta + ";" + child.Depth;

                //depth is a part of the hashCode
                if (visited.ContainsKey(key)) {
                    tempBeta = visited[key].Alpha;
                    this.useOfVisited++;
                }
                else {
                    tempBeta = evaluateMaxState(child, alpha, beta, depth + 0.5);
                }

                if (tempBeta < beta) {
                    beta = tempBeta;
                    //we are at the top of the tree
                    if (state.Parent == null) { 
                        if (this.movesMiniMaxes.ContainsKey(child.RootMove)) {
                            this.movesMiniMaxes[child.RootMove] = tempBeta;
                        }
                        else {
                            this.movesMiniMaxes.Add(child.RootMove, tempBeta);
                        }
                    }
                }

                //pruning condition			
                if (alpha >= beta) {
                    break;
                }
            }

            state.Alpha = alpha;
            state.Beta = beta;

            key = state.ID + ";" + startAlpha + ";" + startBeta + ";" + state.Depth;
            if (!this.visited.ContainsKey(key)) {
                this.visited.Add(key, state);
            }
            else {
                this.visited[key] = state;
            }

            return beta;
        }

        #endregion //end Protected Methods

        #region Public Methods

        /// <summary>
        /// Wykonuje przeszukiwanie alpha-beta.
        /// </summary>
        public void DoSearch() {
            if (isMaximizingPlayerFirst) {
                evaluateMaxState(this.startState, double.NegativeInfinity, double.PositiveInfinity, 0);
            }
            else {
                evaluateMinState(this.startState, double.NegativeInfinity, double.PositiveInfinity, 0);
            }
        }

        #endregion //end Public Methods

    }
}
