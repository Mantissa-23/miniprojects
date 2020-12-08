; First pass

(defn c->i [c] (- (int c) 65))

(defn i->c [i] (char (+ i 65)))

(defn encrypt [message keyword]
  (let [m-upper (map c->i (clojure.string/upper-case message))
        offsetter (map c->i (apply str (take (count message) (cycle (clojure.string/upper-case keyword)))))]
    (apply str (map (fn [c o] (i->c (mod (+ c o) 26))) m-upper offsetter))))

(defn decrypt [message keyword]
  (let [m-upper (map c->i (clojure.string/upper-case message))
        offsetter (map c->i (apply str (take (count message) (cycle (clojure.string/upper-case keyword)))))]
    (apply str (map (fn [c o] (i->c (mod (+ (- c o) 26) 26))) m-upper offsetter))))

(encrypt "ATTACKATDAWN" "LEMON")
(decrypt "LXFOPVEFRNHR" "LEMON")

; Second pass

; Lost to tim : ()

; Third pass

(def i #(- (int %) 65))
(defn a [m k f]
  (let [r (map i m)
        v (map i (cycle k))]
    (apply str (map #(char (+ (mod (f %1 %2) 26) 65)) r v))))
(let [[m k] *command-line-args*
      z (a m k +)]
  (println [z (a z k -)]))

; Final pass, decrypted to be actually readable

(def int->char #(- (int %) 65))

(defn encrypt-decrypt [message key dir]
  (let [message-encoded (map int->char message)
        key-encoded (map int->char (cycle key))]
    (apply str (map 
                 #(char (+ (mod (dir %1 %2) 26) 65))
                 message-encoded
                 key-encoded))))

(let [[message key] *command-line-args*
      encrypted (encrypt-decrypt message key +)]
  (println [encrypted (encrypt-decrypt encrypted key -)]))

(encrypt-decrypt "ATTACKATDAWN" "LEMON" +)
