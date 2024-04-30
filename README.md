<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bus Reservation System</title>
    <style>
        /* CSS styling can be added here */
    </style>
</head>
<body>
    <h1>Bus Reservation System</h1>
    
    <form action="reservation_handler.cgi" method="post">
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required><br><br>
        
        <label for="email">Email:</label>
        <input type="email" id="email" name="email" required><br><br>
        
        <label for="phone">Phone:</label>
        <input type="tel" id="phone" name="phone" pattern="[0-9]{10}" required><br><br>
        
        <label for="bus">Select Bus:</label>
        <select id="bus" name="bus">
            <option value="bus1">Bus 1</option>
            <option value="bus2">Bus 2</option>
            <option value="bus3">Bus 3</option>
            <!-- Add more options as needed -->
        </select><br><br>
        
        <label for="seats">Number of Seats:</label>
        <input type="number" id="seats" name="seats" min="1" max="10" required><br><br>
        
        <input type="submit" value="Reserve">
    </form>
    
    <script>
        // JavaScript functionality can be added here
    </script>
</body>
</html>
