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

(clojure reuse a letencrypt "ATTACKATDAWN" "LEMON")
(decrypt "LXFOPVEFRNHR" "LEMON")
