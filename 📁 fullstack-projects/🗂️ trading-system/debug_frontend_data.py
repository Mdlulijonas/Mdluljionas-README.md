# debug_frontend_data.py
import requests
import json

def debug_frontend_data():
    print("=== FRONTEND DATA DEBUG ===")
    
    try:
        # Test the API endpoint
        response = requests.get('http://localhost:5000/api/update-all')
        data = response.json()
        
        print("✅ API Response Structure:")
        print(f"   Status: {response.status_code}")
        print(f"   Keys: {list(data.keys())}")
        
        print(f"\n📊 Performance Data:")
        performance = data.get('performance', {})
        for key, value in performance.items():
            print(f"   {key}: {value}")
        
        print(f"\n🏛️ Market Regime:")
        regime = data.get('market_regime', {})
        for key, value in regime.items():
            print(f"   {key}: {value}")
        
        print(f"\n📈 Market Data Summary:")
        market_data = data.get('market_data', {})
        print(f"   Total assets: {len(market_data)}")
        
        if market_data:
            print(f"\n🔍 Sample Asset Data:")
            first_symbol = list(market_data.keys())[0]
            asset_data = market_data[first_symbol]
            print(f"   Symbol: {first_symbol}")
            for key, value in list(asset_data.items())[:8]:  # Show first 8 fields
                print(f"     {key}: {value}")
        
        print(f"\n⏰ Timestamp: {data.get('timestamp')}")
        
    except Exception as e:
        print(f"❌ Error: {e}")

if __name__ == "__main__":
    debug_frontend_data()