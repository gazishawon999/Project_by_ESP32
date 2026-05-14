আচ্ছা আমি একটা Arduino project বানাতে চাই।  
যেটা automated টাইপের কিছু একটা হবে।  

মানে ধরো একটা স্মার্ট হোম।  
যেখানে যা যা সিস্টেম থাকবে তা হলো—  

গেটে ঢুকার সময় গাড়ির স্পিড চেক করবে  
দুটো IR sensor নির্দিষ্ট দূরত্বে (১ম টা থেকে ২য় টার দূরত্ব 3cm) বসানো থাকবে।  

এবং LCD display তে দেখাবে।  

যদি স্পিড (আমার আগে থেকে নির্ধারিত) বেশি হয় তাহলে  
Car Parking Gate (servo motor 0 to 90°) খুলবে না।  

পাশাপাশি buzzer একটা নির্দিষ্ট সময় (2/3 second) পর্যন্ত বাজবে।  
একই সাথে LCD স্ক্রিনে Warning দেখাবে।  

কিন্তু স্পিড কম থাকলে গেট খুলে যাবে  
এবং LCD screen এ Welcome দেখাবে।  

এরপর ঘরের দরজায় Arduino IDE apps ব্যবহার করে  
mobile phone দিয়ে connect করে apps থেকে keypad dial করে  
PIN (1234) দিয়ে ডোর লক সিস্টেম বানাতে চাই।  

সেখানে servo motor ব্যবহার করা হবে  
সঠিক PIN দিলে servo motor 0 থেকে 90° যাবে।  

LCD screen এ 3,2,1,0 second countdown দেখাবে  
তারপর দরজা আবার অটোমেটিক বন্ধ হয়ে যাবে।  

ভুল PIN দিলে দরজা খুলবে না।  

এবং পরপর যদি তিনবার ভুল PIN দেওয়া হয়  
তাহলে buzzer 2/3 second বাজবে  
এবং LCD স্ক্রিনে Warning দেখাবে।  

এরপর যখন ঘরের ভিতরে ঢুকবো  
ultrasonic sensor detect করলে  
রুমের লাইট (LED) অটোমেটিক চালু হবে।  

আর project এর দেয়ালের পিছনে security এর জন্য  
Laser Sensor ব্যবহার করতে চাই।  

যদি sensor কিছু detect করে  
তাহলে buzzer বাজবে  
এবং LCD তে Warning দেখাবে।  

একই সাথে যদি একাধিক সমস্যা হয়  
তাহলে priority based system এ  
Laser alarm-টাই আগে কাজ করবে।  

Display হিসেবে 16x2 I2C LCD ব্যবহার করা হবে।  
Door lock control করা হবে mobile app দিয়ে।
