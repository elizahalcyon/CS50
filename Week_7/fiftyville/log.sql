-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28; --- Theft at 10:15 am at the Humphrey Street bakery, three witnesses
SELECT * FROM interviews WHERE transcript LIKE '%Bakery%'; --- car left within 10 minutes; ATM withdrawal at Leggett St; earliest flight next day, under a minute call out
SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25; --- returns 8 vehicles
SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25); --- names of vehicles
SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'; --- 8 people withdrew that day

SELECT name FROM people, bank_accounts, atm_transactions
    WHERE people.id = bank_accounts.person_id
        AND bank_accounts.account_number = atm_transactions.account_number
            AND year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street'
                AND transaction_type = 'withdraw'; --- returned 8 names from ATM security

SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1; --- earliest flight
SELECT * FROM airports WHERE id IN (SELECT origin_airport_id FROM flights WHERE year = 2021 AND month = 7 AND day = 29); --- origin airport
SELECT * FROM airports WHERE id IN (SELECT destination_airport_id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1); --- destination airport


SELECT * FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60; --- 9 phone calls under 1 minute day of theft
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60); --- name of callers (Bruce, Sofia, Diana, Kelsey match vehicles)
SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60); --- receivers
SELECT name FROM people WHERE phone_number = '(375) 555-8161'; --- Bruce called Robin
SELECT name FROM people WHERE phone_number = '(725) 555-3243'; --- Diana called Philip


SELECT name FROM people WHERE passport_number IN
    (SELECT passport_number FROM flights WHERE id IN
        (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1)); --- returns ALL passengers on flight

SELECT people.name FROM people
    JOIN passengers ON people.passport_number = passengers.passport_number
        WHERE flight_id IN
            (SELECT id FROM flights WHERE origin_airport_id = 8 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1); --- Bruce is on flight