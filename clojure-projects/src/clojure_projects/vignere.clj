(def u clojure.string/upper-cse)
(def i #(- (int %) 65))
(def c #(char (+ % 65)))
(def s #(apply str (map %1 %2 %3)))
(defn g [o] #(c (mod (o %1 %2) 26)))

(defn a [m k f]
  (let [r (map i (u m))
        v (map i (cycle (u k)))]
    (f r v)))

(defn e [m k]
  (a m k  #(s (g +) %1 %2)))

(defn d [m k]
  (a m k  #(s (g -) %1 %2)))

(let [[m k] *command-line-args*
      z (e m k)]
  (apply println [z (d z k)]))
