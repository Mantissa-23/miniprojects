(def i #(- (int %) 65))
(defn a [m k f]
  (let [r (map i m)
        v (map i (cycle k))]
    (apply str (map #(char (+ (mod (f %1 %2) 26) 65)) r v))))
(let [[m k] *command-line-args*
      z (a m k +)]
  (println [z (a z k -)]))
