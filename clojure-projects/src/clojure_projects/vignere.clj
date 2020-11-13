(def u clojure.string/upper-case)
(def ci #(- (int %) 65))
(def ic #(char (+ % 65)))
(def as #(apply str (map %1 %2 %3)))
(defn ag [o] #(ic (mod (o %1 %2) 26)))

(defn ed [m k f]
  (let [mu (map ci (u m))
        ku (map ci (cycle (u k)))]
    (f mu ku)))

(defn e [m k]
  (ed m k  #(as (ag +) %1 %2)))

(defn d [m k]
  (ed m k  #(as (ag -) %1 %2)))

(let [[me ke] *command-line-args*
      en (e me ke)]
  (apply println [en (d en ke)]))
